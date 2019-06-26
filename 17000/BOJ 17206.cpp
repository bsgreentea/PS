#include <cstdio>

const int MAX = 80000;

int t, n, a3[MAX + 1], a7[MAX + 1], a21[MAX + 1];

int main() {

	for (int i = 1; i <= MAX; i++) {
		if (i % 3 == 0) a3[i] += i;
		if (i % 7 == 0) a7[i] += i;
		if (i % 21 == 0) a21[i] += i;

		a3[i] += a3[i - 1];
		a7[i] += a7[i - 1];
		a21[i] += a21[i - 1];
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		printf("%d\n", a3[n] + a7[n] - a21[n]);
	}
}