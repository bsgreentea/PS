#include <iostream>

#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;

// 17837
typedef struct {
	int x, y, d, order;
}info;

int n, k, map[15][15][15], numberOf[15][15];
info marker[15];

int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

bool isInbound(int x, int y) {
	return 1 <= x && 1 <= y && x <= n && y <= n;
}

void changeDirection(int& dir) {
	if (dir == 1) dir = 2;
	else if (dir == 2) dir = 1;
	else if (dir == 3) dir = 4;
	else if (dir == 4) dir = 3;
}

int move(int markerNum) {

	int ret = 0;

	int x = marker[markerNum].x;
	int y = marker[markerNum].y;
	int d = marker[markerNum].d;
	int order = marker[markerNum].order;

	int nx = x + dx[d];
	int ny = y + dy[d];

	if (isInbound(nx, ny)) {
		int color = map[nx][ny][0];
		int nextNum = numberOf[nx][ny];

		if (color == WHITE) {
			for (int i = order; i <= numberOf[x][y]; i++) {

				nextNum++;

				int from = map[x][y][i];

				map[nx][ny][nextNum] = from;
				marker[from].x = nx;
				marker[from].y = ny;
				marker[from].order = nextNum;
				map[x][y][i] = 0;
			}

			numberOf[nx][ny] = nextNum;
			numberOf[x][y] = order - 1;

			ret = numberOf[nx][ny];
		}
		else if (color == RED) {
			for (int i = numberOf[x][y]; i >= order; i--) {
				
				nextNum++;

				int from = map[x][y][i];

				map[nx][ny][nextNum] = from;
				marker[from].x = nx;
				marker[from].y = ny;
				marker[from].order = nextNum;
				map[x][y][i] = 0;
			}

			numberOf[nx][ny] = nextNum;
			numberOf[x][y] = order - 1;

			ret = numberOf[nx][ny];
		}
		else {
			//changeDirection(marker[markerNum].d);
		}
	}
	else {
		//changeDirection(marker[markerNum].d);
	}

	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j][0];
		}
	}

	for (int i = 1; i <= k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		marker[i] = { x,y,d,1 };
		map[x][y][1] = i;
		numberOf[x][y] = 1;
	}

	int cnt = 0;
	while (1) {
		cnt++;
		if (cnt > 1000) break;

		int flag = 0;
		for (int i = 1; i <= k; i++) {

			int x = marker[i].x;
			int y = marker[i].y;
			int d = marker[i].d;

			int nx = x + dx[d];
			int ny = y + dy[d];

			if (isInbound(nx, ny)) {
				int color = map[nx][ny][0];
				if (color == BLUE) {
					changeDirection(marker[i].d);
				}
			}
			else { // act like blue
				changeDirection(marker[i].d);
			}

			if (move(i) >= 4) {
				flag = 1;
				break;
			}
		}

		if (flag) break;
	}

	if (cnt > 1000) cout << "-1";
	else cout << cnt;
}