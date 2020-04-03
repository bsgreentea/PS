#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;
const int MAX_HEIGHT = 1e6;

typedef struct {
	int x, y;
}info;

int n, height[MAX + 1][MAX + 1], temp[MAX_HEIGHT + 1], cnt_k, disc[MAX + 1][MAX + 1], sx, sy, hp;
char map[MAX + 1][MAX + 1];

vector<int> vt;

int dx[] = { 0,0,1,1,1,-1,-1,-1 };
int dy[] = { 1,-1,1,-1,0,1,-1,0 };

bool chk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'K') cnt_k++;
			if (map[i][j] == 'P') {
				sx = i; sy = j;
			}
		}
		getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &height[i][j]);
			temp[height[i][j]]++;
			if (map[i][j] == 'P') hp = height[i][j];
		}
	}

	for (int i = 1; i <= MAX_HEIGHT; i++) {
		if (temp[i]) vt.push_back(i);
	}

	int res = MAX_HEIGHT;
	int left = 0, right = 0, disc_num = 0;
	int sz = vt.size();

	while (left <= right && right < sz) {

		if (hp > vt[right]) {
			right++;
			continue;
		}
		if (hp < vt[left]) break;

		int kk = 0;
		queue<info> qu;
		qu.push({ sx, sy });
		disc[sx][sy] = disc_num++;

		while (qu.size()) {

			int x = qu.front().x;
			int y = qu.front().y;
			qu.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!chk(nx, ny) || disc[nx][ny] == disc_num) continue;
				if (height[nx][ny] < vt[left] || height[nx][ny] > vt[right]) continue;

				qu.push({ nx,ny });
				disc[nx][ny] = disc_num;
				if (map[nx][ny] == 'K') kk++;
			}
		}

		if (kk < cnt_k) right++;
		else {
			res = min(res, vt[right] - vt[left]);
			left++;
		}
	}

	printf("%d\n", res);
}