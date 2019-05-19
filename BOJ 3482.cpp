#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
	int a, b, d;
}info;

int t, n, m, disc[1010][1010], sx, sy;

char map[1010][1010];
vector<pair<int, int>> vt;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int find_farthest(int x, int y) {

	int temp_len = 0;

	queue<info> qu;
	
	qu.push({ x,y,0 });
	disc[x][y] = 1;

	while (qu.size()) {

		int len = qu.front().d;
		int hx = qu.front().a;
		int hy = qu.front().b;

		qu.pop();

		if (len > temp_len) {
			temp_len = len;
			sx = hx;
			sy = hy;
		}

		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			if (disc[nx][ny] || map[nx][ny] == '#') continue;

			disc[nx][ny] = 1;
			qu.push({ nx,ny,len + 1 });
		}
	}

	return temp_len;
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < m; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '.') {
					sx = i; sy = j;
				}
			}
		}

		find_farthest(sx, sy);

		memset(disc, 0, sizeof(disc));

		int res = find_farthest(sx, sy);

		memset(disc, 0, sizeof(disc));

		printf("Maximum rope length is %d.\n", res);
	}
}