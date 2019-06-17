#include <cstdio>

int n, m, from[55][55], to[55][55];

void toggle(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			from[i][j] = 1 - from[i][j];
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &from[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &to[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (from[i][j] != to[i][j]) {
				toggle(i, j); cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (from[i][j] != to[i][j]) cnt = -1;
		}
	}

	printf("%d\n", cnt);
}