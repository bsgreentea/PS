#include <cstdio>

int n, q, chk[10101];

int main() {

	scanf("%d %d", &n, &q);

	int a, b;
	while (q--) {
		scanf("%d %d", &a, &b);
		for (int i = a; i <= n; i += b) {
			chk[i]++;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += chk[i] == 0;
	}

	printf("%d\n", res);
}