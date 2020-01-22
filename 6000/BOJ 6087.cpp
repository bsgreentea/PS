#include <cstdio>
#include <queue>
using namespace std;

const int INF = 1e9;

typedef struct {
	int x, y, cnt, dir;
}info;

int w, h, disc[111][111][4], fx, fy, tx, ty;
char map[111][111];

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}

int main() {

	scanf("%d %d", &w, &h);

	int flag = 1;
	for (int i = 0; i < h; i++) {
		getchar();
		for (int j = 0; j < w; j++) {
			scanf("%c", &map[i][j]);
			
			for (int k = 0; k < 4; k++) disc[i][j][k] = INF;

			if (map[i][j] == 'C') {
				if (flag) {
					flag = 0;
					fx = i; fy = j;
				}
				else {
					tx = i; ty = j;
				}
			}
		}
	}

	queue<info> qu;

	for (int i = 0; i < 4; i++) {
		qu.push({ fx, fy, 0, i });
	}

	while (qu.size()) {

		int hx = qu.front().x;
		int hy = qu.front().y;
		int cnt = qu.front().cnt;
		int dir = qu.front().dir;
		qu.pop();

		if (hx == tx && hy == ty) continue;

		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			
			if (dir + i == 3) continue;
			int temp_cnt = 0;
			if (dir != i) temp_cnt = 1;

			if (!chk(nx, ny) || map[nx][ny] == '*') continue;
			if (disc[nx][ny][i] > cnt) {
				qu.push({ nx,ny,cnt + temp_cnt, i });
				disc[nx][ny][i] = cnt + temp_cnt;
			}
		}
	}

	int res = INF;
	for (int i = 0; i < 4; i++) {
		if (disc[tx][ty][i] < res) res = disc[tx][ty][i];
	}

	printf("%d\n", res);
}