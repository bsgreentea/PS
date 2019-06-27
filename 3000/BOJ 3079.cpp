#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MAX = 1e18;

ll n, m, t[100100];

ll solve() {

	ll left = 0, right = MAX, mid;
	ll res = MAX;

	while (left <= right) {

		mid = (left + right) / 2;

		ll tot = 0;
		for (ll i = 0; i < n; i++) {
			tot += mid / t[i];
			if (tot >= m) break;
		}

		if (tot >= m) {
			res = min(res, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return res;
}

int main() {

	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", t + i);
	}

	sort(t, t + n);

	printf("%lld\n", solve());
}