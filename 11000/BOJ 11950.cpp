#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, cnt[55][3], to_white[55], to_blue[55], to_red[55];
char map[55][55];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'W') cnt[i][0]++;
			else if (map[i][j] == 'B') cnt[i][1]++;
			else cnt[i][2]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		to_white[i] = cnt[i][1] + cnt[i][2];
		to_blue[i] = cnt[i][0] + cnt[i][2];
		to_red[i] = cnt[i][0] + cnt[i][1];
	}

	int res = 1e9, temp = 0;
	for (int i = 2; i < n; i++) {
		for (int j = i; j < n; j++) {
			temp = 0;
			for (int w = 1; w < i; w++) {
				temp += to_white[w];
			}
			for (int b = i; b <= j; b++) {
				temp += to_blue[b];
			}
			for (int r = j + 1; r <= n; r++) {
				temp += to_red[r];
			}
			res = min(res, temp);
		}
	}

	printf("%d\n", res);
}