#include <cstdio>
#include <algorithm>
using namespace std;

int n, cost[505][505], dp[505][505];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int func(int x, int y) {

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!chk(nx, ny)) continue;
		if (cost[x][y] < cost[nx][ny]) {
			ret = max(ret, func(nx, ny) + 1);
		}
	}

	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
			dp[i][j] = -1;
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1) res = max(res, func(i, j));
		}
	}

	printf("%d\n", res);
}