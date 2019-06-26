#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int l, r, c, map[33][33][33], disc[33][33][33];

int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int chk(int x, int y, int z) {
	return x >= 0 && y >= 0 && z >= 0 && x < r && y < c && z < l;
}

int main() {

	while (1) {

		scanf("%d %d %d", &l, &r, &c);
		if (l + r + c == 0) break;

		queue<pair<int, pair<int, int>>> qu;

		char ch;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				getchar();
				for (int k = 0; k < c; k++) {
					scanf("%c", &ch);
					if (ch == '.')
						map[i][j][k] = 0;
					else if (ch == '#')
						map[i][j][k] = 1;
					else if (ch == 'S') {
						map[i][j][k] = 2;
						qu.push({ i,{j,k} });
						disc[i][j][k] = 1;
					}
					else if (ch == 'E')
						map[i][j][k] = 3;
				}
			}
			getchar();
		}

		int flag = 0, cnt = 0;
		while (qu.size()) {
			int qs = qu.size();
			while (qs--) {
				int hz = qu.front().first;
				int hx = qu.front().second.first;
				int hy = qu.front().second.second;
				qu.pop();

				for (int i = 0; i < 6; i++) {
					int nx = hx + dx[i];
					int ny = hy + dy[i];
					int nz = hz + dz[i];

					if (!chk(nx, ny, nz) || disc[nz][nx][ny] || map[nz][nx][ny] == 1) continue;
					
					qu.push({ nz,{nx,ny} });
					disc[nz][nx][ny] = 1;
					if (map[nz][nx][ny] == 3) {
						flag = 1; break;
					}
				}
			}
			cnt++;
			if (flag) break;
		}

		if (flag)
			printf("Escaped in %d minute(s).\n", cnt);
		else puts("Trapped!");

		memset(disc, 0, sizeof(disc));
	}
}