#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, chk[50001];
vector<ll> ice[1000001], cow[50001];

int main() {

	scanf("%lld", &n);

	ll a;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < 5; j++) {
			scanf("%lld", &a);
			ice[a].push_back(i);
			cow[i].push_back(a);
		}
	}

	ll sz = 0;

	for (ll i = 1; i <= n; i++) {
		ll temp = 0, flag = 0;
		for (ll j = 0; j < 5; j++) {
			
			ll f = cow[i][j];
			
			ll k = upper_bound(ice[f].begin(), ice[f].end(), i) - ice[f].begin();
			for (; k < ice[f].size(); k++) {
				
				ll next = ice[f][k];
				if (chk[next] != i) {
					chk[next] = i;
					temp++;
					if (temp == n - i) {
						flag = 1;
						break;
					}
				}
			}
			if (flag) break;
		}
		sz += temp;
	}

	ll res = (n * n - n) / 2 - sz;

	printf("%lld\n", res);
}