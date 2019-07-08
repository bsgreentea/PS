#include <cstdio>

int a, b, n, w;

int main() {

	scanf("%d %d %d %d", &a, &b, &n, &w);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a*i + b * (n - i) == w) {
			if (i == 0 || n - i == 0) continue;
			cnt++;
		}
	}

	if (cnt != 1) {
		puts("-1");
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (a*i + b * (n - i) == w) {
			if (i == 0 || n - i == 0) continue;
			printf("%d %d\n", i, n - i);
			return 0;
		}
	}
}