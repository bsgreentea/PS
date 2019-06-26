#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, map[22][22], disc[22][22];

vector<pair<int, int>> vt, enemy[222];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n &&y < m;
}

void group_enemy(int x, int y, int g) {

	enemy[g].push_back({ x,y });
	disc[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx,ny) && !disc[nx][ny] && map[nx][ny] == 2)
			group_enemy(nx, ny, g);
	}
}

int counting(int g) {
	int cnt = 0;

	for (int i = 0; i < enemy[g].size(); i++) {
		for (int j = 0; j < 4; j++) {
			int nx = enemy[g][i].first + dx[j];
			int ny = enemy[g][i].second + dy[j];
			if (chk(nx, ny) && map[nx][ny] == 0) {
				return 0;
			}
		}
		cnt++;
	}
	return cnt;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (!map[i][j]) {
				vt.push_back({ i,j });
			}
		}
	}

	int g_num = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (disc[i][j]) continue;
			if (map[i][j] == 2) {
				group_enemy(i, j, ++g_num);
			}
		}
	}

	int x, y, xx, yy, temp = 0, res = 0;
	for (int i = 0; i < vt.size(); i++) {
		x = vt[i].first;
		y = vt[i].second;
		map[x][y] = 1;
		for (int j = i + 1; j < vt.size(); j++) {
			xx = vt[j].first;
			yy = vt[j].second;
			map[xx][yy] = 1;
			temp = 0;
			for (int k = 0; k <= g_num; k++) {
				temp += counting(k);
			}
			res = res > temp ? res : temp;
			map[xx][yy] = 0;
		}
		map[x][y] = 0;
	}																											

	printf("%d\n", res);
}