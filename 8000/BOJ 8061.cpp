#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1e9;

typedef struct {
	int x, y, cnt;
}info;

int board[200][200], n, m, dist[200][200];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<info> qu;

bool chk(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs() {

	while (qu.size()) {

		int x = qu.front().x;
		int y = qu.front().y;
		int cnt = qu.front().cnt;
		qu.pop();

		dist[x][y] = cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!chk(nx, ny) || board[nx][ny] || dist[nx][ny] <= cnt + 1) continue;

			qu.push({ nx,ny,cnt + 1 });
			dist[nx][ny] = cnt + 1;
		}

	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = MAX;
			scanf("%1d", &board[i][j]);
			if (board[i][j]) qu.push({ i,j,0 });
		}
	}

	bfs();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) printf("%d ", dist[i][j]);
		puts("");
	}
}