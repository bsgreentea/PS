#include <cstdio>

int n, m, map[1033][1033], k, psum[1033][1033];

int main() {

	scanf("%d %d", &n, &m);

	int row_sum = 0;
	for (int i = 1; i <= n; i++) {
		row_sum = 0;
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			row_sum += map[i][j];
			psum[i][j] = psum[i - 1][j] + row_sum;
		}
	}

	scanf("%d", &k);
	int a, b, c, d;
	while (k--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", psum[c][d] - psum[a - 1][d] - psum[c][b - 1] + psum[a - 1][b - 1]);
	}
}