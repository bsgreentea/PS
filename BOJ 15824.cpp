#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll n, p[300300], power[300300];

int main() {

	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", p + i);
	}

	power[0] = 1;
	for (ll i = 1; i <= n; i++) {
		power[i] = power[i - 1] * 2;
		power[i] %= MOD;
	}

	sort(p, p + n);

	ll res = 0;

	for (ll i = 0; i < n; i++) {
		res += (p[i] % MOD) * (power[i] - power[n - i - 1]);
		res += MOD;
		res %= MOD;
	}

	printf("%lld\n", res);
}