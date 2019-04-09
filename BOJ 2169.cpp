#include <cstdio>
#include <algorithm>
using namespace std;

//2169

const int INIT_V = -1e9;

int n, m, map[1010][1010], dp[3][1010][1010], visited[1010][1010];

int dx[] = { 0,1,0 };
int dy[] = { 1,0,-1 };

bool chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int solve(int dir, int x, int y) {

	if (x == n - 1 && y == m - 1)
		return map[x][y];

	if (dp[dir][x][y] != INIT_V) return dp[dir][x][y];

	visited[x][y] = 1;

	//int temp[3];
	//for (int i = 0; i < 3; i++) temp[i] = INIT_V;

	//if (y + 1 < m && !visited[x][y + 1])
	//	temp[0] = solve(0, x, y + 1);
	//if (x + 1 < n && !visited[x + 1][y])
	//	temp[1] = solve(1, x + 1, y);
	//if (y - 1 >= 0 && !visited[x][y - 1])
	//	temp[2] = solve(2, x, y - 1);

	//temp[0] = max(temp[0], temp[1]);
	//temp[0] = max(temp[0], temp[2]);
	int temp[3];
	for (int i = 0; i < 3; i++) temp[i] = INIT_V;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!chk(nx, ny) || visited[nx][ny]) continue;
		temp[0] = max(temp[0],solve(i, nx, ny));
	}

	visited[x][y] = 0;

	return dp[dir][x][y] = map[x][y] + temp[0];
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);

			for (int k = 0; k < 3; k++) dp[k][i][j] = INIT_V;
		}
	}

	printf("%d\n", solve(0, 0, 0));
}