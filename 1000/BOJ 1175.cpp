#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y, dir, cnt, c1, c2;
}info;

int n, m, num_c, sx, sy, dp[50][50][4][2][2];
char map[55][55];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool chk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {

	scanf("%d %d\n", &n, &m);

	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'C' && flag) {
				map[i][j] = 'c';
				flag = false;
			}
			if (map[i][j] == 'S') sx = i, sy = j;
		}getchar();
	}

	int res = 1e9;

	queue<info> qu;

	qu.push({ sx,sy,4, 0, 0 });

	while (qu.size()) {

		int x = qu.front().x;
		int y = qu.front().y;
		int dir = qu.front().dir;
		int cnt = qu.front().cnt;
		int c1 = qu.front().c1;
		int c2 = qu.front().c2;
		qu.pop();

		if (c1 + c2 == 2) {
			res = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {

			if (i == dir) continue;

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!chk(nx, ny) || map[nx][ny] == '#' || dp[nx][ny][i][c1][c2]) continue;

			int cc1 = c1, cc2 = c2;
			if (map[nx][ny] == 'c') cc1 = 1;
			if (map[nx][ny] == 'C') cc2 = 1;
			qu.push({ nx,ny,i,cnt + 1,cc1,cc2 });
			dp[nx][ny][i][cc1][cc2] = 1;
		}
	}

	if (res == 1e9) res = -1;
	printf("%d\n", res);
}