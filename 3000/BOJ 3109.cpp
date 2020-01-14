#include <cstdio>

const int MAX_R = 1e4;
const int MAX_C = 500;

int r, c, visited[MAX_R + 1][MAX_C + 1];
char map[MAX_R + 1][MAX_C + 1];

int dx[] = { -1,0,1 };
int dy[] = { 1,1,1 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < r && y < c;
}

int search(int x, int y) {

	if (visited[x][y] || map[x][y] == 'x') return 1;
	if (y == c - 1) {
		return visited[x][y] = 2;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!chk(nx, ny)) continue;
		int temp = search(nx, ny);
		if (temp == 1) visited[x][y] = 1;
		if (temp == 2) return visited[x][y] = 2;
	}

	return 0;
}

int main() {

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) {
			scanf("%c", &map[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		cnt += (search(i, 0) == 2 ? 1 : 0);
	}

	printf("%d\n", cnt);
}