#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, map[3003][3003], disc[3003][3003];

queue<pair<int, int>> qu;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
			if (map[i][j] == 2) { qu.push({ i,j }); disc[i][j]++; }
		}
	}

	int cnt = 0, flag = 0;
	while (qu.size()) {
		int qs = qu.size();
		while (qs--) {
			int hx = qu.front().first;
			int hy = qu.front().second;
			qu.pop();

			for (int i = 0; i < 4; i++) {
				int nx = hx + dx[i];
				int ny = hy + dy[i];

				if (!chk(nx, ny) || disc[nx][ny] || map[nx][ny] == 1) continue;
				
				if (map[nx][ny]) {
					flag = 1;
					break;
				}
				else {
					disc[nx][ny] = 1;
					qu.push({ nx,ny });
				}
			}
			if (flag) break;
		}
		cnt++;
		if (flag) break;
	}

	if (flag) {
		cout << "TAK\n" << cnt << '\n';
	}
	else {
		cout << "NIE\n";
	}
}