#include <cstdio>
#include <queue>
#include <deque>
using namespace std;

typedef struct STRUCT {
	int x, y, l, r;
} st;

int n, m, l, r, map[1010][1010];
deque<st> dq;

int dx[] = { 1,-1 };
int dy[] = { 0,0 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && !map[x][y];
}

int main() {

	scanf("%d %d %d %d", &n, &m, &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 2)
				dq.push_back({ i,j,l,r });
		}
	}

	while (dq.size()) {
		st h = dq.front();
		dq.pop_front();

		int nx, ny;
		for (int i = 0; i < 2; i++) {
			nx = h.x + dx[i];
			ny = h.y + dy[i];
			if (!chk(nx, ny)) continue;

			dq.push_front({ nx,ny,h.l,h.r });
			map[nx][ny] = 2;
		}

		if (h.l && chk(h.x, h.y - 1)) {
			dq.push_back({ h.x, h.y - 1, h.l - 1, h.r });
			map[h.x][h.y - 1] = 2;
		}
		if (h.r && chk(h.x, h.y + 1)) {
			dq.push_back({ h.x, h.y + 1, h.l, h.r - 1 });
			map[h.x][h.y + 1] = 2;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) cnt++;
		}
	}

	printf("%d\n", cnt);
}