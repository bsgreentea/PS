#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define LAKE 0
#define	NO 1
#define YES 2
#define FLOWER -1

using namespace std;

const int MAX = 50;

int n, m, g, r, park[MAX + 1][MAX + 1], ans, visited[MAX + 1][MAX + 1];
int green_visit[MAX + 1][MAX + 1], red_visit[MAX + 1][MAX + 1];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> points;

bool chk(int x, int y) {
	return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {

	scanf("%d %d %d %d", &n, &m, &g, &r);

	int land;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			scanf("%d", &land);

			park[i][j] = land;

			if (land == YES) {
				points.push_back({ i,j });
			}
		}
	}

	vector<int> container;
	for (int i = 0; i < g; i++) {
		container.push_back(0);
	}
	for (int i = 0; i < r; i++) {
		container.push_back(1);
	}
	int ps = points.size();
	for (int i = g + r; i < ps; i++) {
		container.push_back(2);
	}

	do {

		queue<pair<int, int>> green, red;
		for (int i = 0; i < container.size(); i++) {
			int xx = points[i].first;
			int yy = points[i].second;

			if (container[i] == 0) {
				green.push(points[i]);
				green_visit[xx][yy] = 1;
			}
			else if (container[i] == 1) {
				red.push(points[i]);
				red_visit[xx][yy] = 1;
			}
		}

		int flower = 0, time = 1;
		while (!green.empty() && !red.empty()) {

			time++;

			int gs = green.size();
			while (gs--) {

				int x = green.front().first;
				int y = green.front().second;
				green.pop();

				if (visited[x][y]) continue;

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (!chk(nx, ny) || park[nx][ny] == LAKE || green_visit[nx][ny] || red_visit[nx][ny] || visited[nx][ny]) continue;

					green.push({ nx,ny });
					green_visit[nx][ny] = time;
				}
			}

			int rs = red.size();
			while (rs--) {

				int x = red.front().first;
				int y = red.front().second;
				red.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (!chk(nx, ny) || park[nx][ny] == LAKE || red_visit[nx][ny] || visited[nx][ny]) continue;

					if (green_visit[nx][ny] == time) {
						flower++;
						visited[nx][ny] = FLOWER;
					}
					else if (green_visit[nx][ny] == 0) {
						red.push({ nx,ny });
						red_visit[nx][ny] = time;
					}
				}
			}
		}

		ans = max(ans, flower);

		memset(visited, 0, sizeof(visited));
		memset(green_visit, 0, sizeof(green_visit));
		memset(red_visit, 0, sizeof(red_visit));

	} while (next_permutation(container.begin(), container.end()));

	printf("%d\n", ans);
}