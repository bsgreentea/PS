#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500
#define INF 1e9

int t, k, c[MAX + 1], dp[MAX + 1][MAX + 1], sum[MAX + 1];

int Min(int a, int b) {
	return a < b ? a : b;
}

int func(int left, int right) {
	
	if (left == right) return 0;
	if (left + 1 == right) return c[left] + c[right];

	int* ret = &dp[left][right];

	if (*ret != -1) return *ret;

	*ret = INF;

	for (int i = left; i < right; i++) {
		*ret = Min(*ret, func(left, i) + func(i + 1, right));
	}

	return *ret += sum[right] - sum[left - 1];
}

void main() {

	scanf("%d", &t);
	while (t--) {

		memset(dp, -1, sizeof(dp));

		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d", c + i);
			sum[i] = sum[i - 1] + c[i];
		}

		printf("%d\n", func(1, k));
	}
}