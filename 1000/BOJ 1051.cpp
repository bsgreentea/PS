#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, map[55][55];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int res = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			temp = min(n - i, m - j);
			for (int k = 1; k < temp; k++) {
				if (map[i][j] == map[i + k][j] && map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j + k]) {
					res = max(res, k*k + 2*k + 1);
				}
			}
		}
	}

	printf("%d\n", res);
}