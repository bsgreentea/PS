#include <cstdio>

typedef long long ll;

ll t, n;

int main() {

	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);

		ll temp = 1;
		while (temp <= n) {
			temp *= 10;
		}

		ll a = temp * 10 * n - n;
		ll b = temp * n - n;

		//printf("%lld %lld\n", a, b);

		temp = a;

		ll sum = 0;
		while (a) {
			sum += a % 10;
			a /= 10;
		}

		printf("%lld\n", sum % 2 ? temp : b);
	}
}