#include <cstdio>

typedef long long ll;

const ll MOD = 1e6;
const ll period = 1e5 * 15;

ll n, fibo[period];

int main() {

	fibo[1] = 1;

	scanf("%lld", &n);
	for (ll i = 2; i < period; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= MOD;
	}

	printf("%lld\n", fibo[n%period]);
}