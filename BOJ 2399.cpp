#include <cstdio>

int n, num[10010];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", num + i);
	}

	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res += (num[i] - num[j] > num[j] - num[i] ? num[i] - num[j] : num[j] - num[i]);
		}
	}

	printf("%lld\n", res);
}