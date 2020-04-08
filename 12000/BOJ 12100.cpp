#include <cstdio>
#include <algorithm>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

int n, board[20][20], ans, from[20];

int biggest() {

	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, board[i][j]);

	return ret;
}

void update(int dir) {

	for (int i = 0; i < n; i++) from[i] = 0;

	if (dir == UP) {
		for (int i = 0; i < n; i++) {
			int idx = 0;
			for (int j = 0; j < n; j++) {
				if (board[j][i]) from[idx++] = board[j][i];
			}
			for (int j = 0; j < n - 1; j++) {
				if (from[j] == from[j + 1]) {
					from[j] += from[j + 1];
					from[j + 1] = 0;
					j++;
				}
			}
			idx = 0;
			for (int j = 0; j < n; j++) {
				if (from[j]) board[idx++][i] = from[j];
				from[j] = 0;
			}
			while (idx < n) {
				board[idx++][i] = 0;
			}
		}
	}
	else if (dir == DOWN) {
		for (int i = 0; i < n; i++) {
			int idx = n - 1;
			for (int j = n - 1; j >= 0; j--) {
				if (board[j][i]) from[idx--] = board[j][i];
			}
			for (int j = n - 1; j >= 0; j--) {
				if (from[j] == from[j - 1]) {
					from[j] += from[j - 1];
					from[j - 1] = 0;
					j--;
				}
			}
			idx = n - 1;
			for (int j = n - 1; j >= 0; j--) {
				if (from[j]) board[idx--][i] = from[j];
				from[j] = 0;
			}
			while (idx >= 0) {
				board[idx--][i] = 0;
			}
		}
	}
	else if (dir == LEFT) {
		for (int i = 0; i < n; i++) {
			int idx = 0;
			for (int j = 0; j < n; j++) {
				if (board[i][j]) from[idx++] = board[i][j];
			}
			for (int j = 0; j < n - 1; j++) {
				if (from[j] == from[j + 1]) {
					from[j] += from[j + 1];
					from[j + 1] = 0;
					j++;
				}
			}
			idx = 0;
			for (int j = 0; j < n; j++) {
				if (from[j]) board[i][idx++] = from[j];
				from[j] = 0;
			}
			while (idx < n) {
				board[i][idx++] = 0;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			int idx = n - 1;
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j]) from[idx--] = board[i][j];
			}
			for (int j = n - 1; j >= 0; j--) {
				if (from[j] == from[j - 1]) {
					from[j] += from[j - 1];
					from[j - 1] = 0;
					j--;
				}
			}
			idx = n - 1;
			for (int j = n - 1; j >= 0; j--) {
				if (from[j]) board[i][idx--] = from[j];
				from[j] = 0;
			}
			while (idx >= 0) {
				board[i][idx--] = 0;
			}
		}
	}
}

void solve(int cnt) {

	if (cnt == 5) {
		ans = max(ans, biggest());
		return;
	}

	int temp[20][20];

	for (int i = 0; i < 4; i++) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = board[i][j];

		update(i);
		solve(cnt + 1);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = temp[i][j];
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	solve(0);

	printf("%d\n", ans);
}