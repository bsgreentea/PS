#include <cstdio>

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 4000000;

ll n, k, fac[MAX + 1], inverse[MAX + 1];

ll power(ll x, ll y) {

	ll ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return ret;
}

int main() {

	fac[1] = 1;
	for (ll i = 2; i <= MAX; i++)
		fac[i] = (fac[i - 1] * i) % MOD;
	inverse[MAX] = power(fac[MAX], MOD - 2);
	for (ll i = MAX - 1; i >= 0; i--)
		inverse[i] = (inverse[i + 1] * (i + 1)) % MOD;

	scanf("%lld %lld", &n, &k);
	
	if (n == k || k == 0) {
		puts("1"); return 0;
	}

	ll res = (fac[n] * inverse[n - k]) % MOD;
	res = (res*inverse[k]) % MOD;

	printf("%lld\n", res);
}