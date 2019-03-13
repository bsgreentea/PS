#include <cstdio>

int n, m, map[505][505], dp[505][505];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dfs(int x, int y) {

	if (x == n - 1 && y == m - 1) return 1;
	
	if (dp[x][y] == -1) {
		dp[x][y] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!chk(nx, ny)) continue;
			if (map[nx][ny] < map[x][y]) {
				dp[x][y] += dfs(nx, ny);
			}
		}
	}

	return dp[x][y];
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dfs(0,0));
}