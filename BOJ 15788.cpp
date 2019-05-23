#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

ll n, map[505][505], x, y;

ll solve(ll chk) {

	ll vertical, horizon;
	set<ll> st;

	if (chk) {
		map[x][y] = chk;
	}

	for (ll i = 0; i < n; i++) {
		vertical = horizon = 0;
		for (ll j = 0; j < n; j++) {
			horizon += map[i][j];
			vertical += map[j][i];
		}
		st.insert(vertical);
		st.insert(horizon);
	}

	ll a, b;
	a = b = 0;
	for (ll i = 0; i < n; i++) {
		a += map[i][i];
		b += map[i][n - i - 1];
	}
	st.insert(a);
	st.insert(b);

	if (chk) {
		if (st.size() == 1) return chk;
		else return -1;
	}

	ll ret;
	if (st.size() != 2) {
		ret = -1LL;
	}
	else {
		ll temp[2], cnt = 0;
		for (set<ll>::iterator it = st.begin(); it != st.end(); it++) {
			temp[cnt++] = *it;
		}
		ret = max(temp[1] - temp[0], temp[0] - temp[1]);
	}

	return ret;
}

int main() {

	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			scanf("%lld", &map[i][j]);
			if (map[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}

	printf("%lld\n", solve(solve(0)));
}