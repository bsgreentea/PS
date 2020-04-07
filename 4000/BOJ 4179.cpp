#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 1e9;

typedef struct {
	int x, y;
}info;

int r, c;
char map[1010][1010];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool chk(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c && map[x][y] != '#';
}

bool chk_edge(int x, int y) {
	return x == 0 || x == r - 1 || y == 0 || y == c - 1;
}

int main() {

	queue<info> jihoon, fire;

	int res = MAX;

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'F') fire.push({ i,j });
			if (map[i][j] == 'J') {
				jihoon.push({ i,j });
				if (chk_edge(i, j)) res = 0;
			}
		}
	}
	
	if (res == 0) {
		puts("1"); return 0;
	}

	int cnt = 0;

	while (!jihoon.empty() || !fire.empty()) {

		cnt++;

		int qs = fire.size();
		while (qs--) {

			int x = fire.front().x;
			int y = fire.front().y;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!chk(nx, ny) || map[nx][ny] == 'F') continue;

				fire.push({ nx,ny });
				map[nx][ny] = 'F';
			}
		}

		qs = jihoon.size();
		while (qs--) {

			int x = jihoon.front().x;
			int y = jihoon.front().y;
			jihoon.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!chk(nx, ny) || map[nx][ny] == 'F' || map[nx][ny] == 'J') continue;

				jihoon.push({ nx, ny });
				map[nx][ny] = 'J';

				if (chk_edge(nx, ny)) {
					printf("%d\n", cnt + 1); return 0;
				}
			}
		}
	}

	puts("IMPOSSIBLE");
}