#include <cstdio>
#include <queue>
using namespace std;

int n, m, p, s[10], res[10], map[1010][1010], tot;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<int> qu1;
queue<pair<int, int>> qu2[10];

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {

	scanf("%d %d %d", &n, &m, &p);

	tot = m * n;

	for (int i = 1; i <= p; i++) {
		scanf("%d", s + i);
	}

	char ch;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &ch);
			if (ch == '.') map[i][j] = 0;
			else if (ch == '#') {
				map[i][j] = -1;
				tot--;
			}
			else if ('1' <= ch && ch <='9') {
				map[i][j] = ch - '0';
				qu2[map[i][j]].push({ i,j });
				res[map[i][j]]++;
				tot--;
			}
		}
	}

	for (int i = 1; i <= p; i++) {
		qu1.push(i);
	}

	while (!qu1.empty()) {

		int player = qu1.front();
		qu1.pop();

		for (int i = 0; i < s[player]; i++) {
			int qs = qu2[player].size();
			if (qs == 0) break;
			while (qs--) {
				int hx = qu2[player].front().first;
				int hy = qu2[player].front().second;
				qu2[player].pop();

				for (int j = 0; j < 4; j++) {
					int nx = hx + dx[j];
					int ny = hy + dy[j];

					if (!chk(nx, ny) || map[nx][ny] != 0) continue;
					map[nx][ny] = player;
					res[player]++;
					tot--;
					if (!tot) {
						for (int i = 1; i <= p; i++) {
							printf("%d ", res[i]);
						}
						puts("");
						return 0;
					}
					qu2[player].push({ nx,ny });
				}
			}
		}
		if (qu2[player].size()) qu1.push(player);
	}

	for (int i = 1; i <= p; i++) {
		printf("%d ", res[i]);
	}puts("");
}