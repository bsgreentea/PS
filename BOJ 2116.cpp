#include <cstdio>
#include <algorithm>
using namespace std	;

int n, dice[10100][7], p[10100][7];

int maxn(int i, int j) {
	if (j == 1 || j == 6)
		return max(max(dice[i][2], dice[i][3]), max(dice[i][4], dice[i][5]));
	else if (j == 2 || j == 4)
		return max(max(dice[i][1], dice[i][3]), max(dice[i][5], dice[i][6]));
	else if (j == 3 || j == 5)
		return max(max(dice[i][1], dice[i][2]), max(dice[i][4], dice[i][6]));
}

int opposite_num(int i, int num) {
	int temp = p[i][num];
	if (temp == 1) return dice[i][6];
	if (temp == 2) return dice[i][4];
	if (temp == 3) return dice[i][5];
	if (temp == 4) return dice[i][2];
	if (temp == 5) return dice[i][3];
	if (temp == 6) return dice[i][1];
}

int func(int num) {
	
	int ret = 0;
	int now = num;

	for (int i = 0; i < n; i++) {
		ret += maxn(i, p[i][now]);
		now = opposite_num(i, now);
	}

	return ret;
}

int main() {

	scanf("%d", &n);

	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf("%d", &a);
			dice[i][j] = a;
			p[i][a] = j;
		}
	}

	int res = 0;
	for (int i = 1; i <= 6; i++) {
		res = max(res, func(i));
	}

	printf("%d\n", res);
}