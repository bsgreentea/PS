#include <cstdio>

typedef long long ll;

ll n, num;

int main() {

	scanf("%lld", &n);

	ll sum = 0;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &num);
		sum += num;
		sum -= i;
	}
	printf("%lld\n", sum + n);
}