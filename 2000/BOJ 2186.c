#include <stdio.h>
#include <string.h>

int n, m, k, dp[101][101][101], str_len;
char board[101][101], str[82];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dfs(int x, int y, int th) {

	if (dp[x][y][th] != -1) return dp[x][y][th];
	if (th >= str_len) return 1;

	int* ret = &dp[x][y][th];
	
	*ret = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			if (!chk(nx, ny)) continue;
			if (board[nx][ny] != str[th]) continue;

			*ret += dfs(nx, ny, th + 1);
		}
	}

	return *ret;
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &board[i][j]);
		}
	}

	getchar();

	scanf("%s", str);
	str_len = strlen(str);

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == str[0])
				cnt += dfs(i, j, 1);
		}
	}

	printf("%d\n", cnt);
}