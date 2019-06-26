#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 303;

int t, n, disc[MAX][MAX], x[2], y[2];

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d %d %d %d", x, y, x + 1, y + 1);

		if (x[0] == x[1] && y[0] == y[1]) {
			puts("0"); continue;
		}

		queue<pair<int, int>> qu;
		qu.push({ x[0],y[0] });

		disc[x[0]][y[0]] = 1;

		int cnt = 0, flag = 0;
		while (qu.size()) {
			int qs = qu.size();

			while (qs--) {
				int hx = qu.front().first;
				int hy = qu.front().second;
				qu.pop();

				for (int i = 0; i < 8; i++) {
					int nx = hx + dx[i];
					int ny = hy + dy[i];
					if (disc[nx][ny] || !chk(nx, ny)) continue;

					if (nx == x[1] && ny == y[1]) {
						flag = 1; break;
					}

					qu.push({ nx,ny });
					disc[nx][ny] = 1;
				}
				if (flag) break;
			}
			cnt++;
			if (flag) break;
		}

		printf("%d\n", cnt);

		memset(disc, 0, sizeof(disc));
	}
}