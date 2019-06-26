#include <cstdio>

typedef long long ll;

const ll MAX = 2000000;

ll n, k, num[MAX + 1], cnt, res;

int main() {

	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &k);
		num[k]++;
	}

	res = n;

	for (ll i = 1; i <= MAX; i++) {
		cnt = 0;
		for (ll j = i; j <= MAX; j += i) {
			cnt += num[j];
		}
		if (cnt > 1)
			res = res > (cnt * i) ? res : (cnt * i);
	}

	printf("%lld\n", res);
}