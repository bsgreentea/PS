#include <cstdio>

int n, map[55][55], cnt[55];

int main() {

	scanf("%d", &n);
	char ch;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) {
			scanf("%c", &ch);
			if (ch == 'Y') map[i][j] = 1;
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (map[i][j]) {
				cnt[i]++;
				res = res > cnt[i] ? res : cnt[i];
				continue;
			}
			for (int k = 0; k < n; k++) {
				if (i == k || j == k) continue;
				if (map[i][k] && map[j][k]) {
					cnt[i]++;
					res = res > cnt[i] ? res : cnt[i];
					break;
				}
			}
		}
	}

	printf("%d\n", res);
}