#include <cstdio>

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 10101;

ll n, m, fac[MAX + 1], inv[MAX + 1];

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

	scanf("%lld %lld", &n, &m);

	fac[1] = 1;
	for (ll i = 2; i <= MAX; i++)
		fac[i] = (fac[i - 1] * i) % MOD;

	inv[MAX] = power(fac[MAX], MOD - 2);

	for (ll i = MAX - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;

	ll res = 0, temp;
	for (ll i = 0; i <= n / m; i++) {
		temp = (fac[n - (m - 1)*i] * inv[n - (m - 1)*i - i]) % MOD;
		temp = (temp*inv[i]) % MOD;
		res += temp;
		res %= MOD;
	}

	printf("%lld\n", res);
}