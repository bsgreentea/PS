#include <cstdio>

int n;
char board[255][5][7];

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			getchar();
			for (int k = 0; k < 7; k++) {
				scanf("%c", &board[i][j][k]);
			}
		}
	}

	int cnt = 100, aa, bb;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int temp = 0;
			for (int a = 0; a < 5; a++) {
				for (int b = 0; b < 7; b++) {
					if (board[i][a][b] != board[j][a][b]) temp++;
				}
			}
			if (temp < cnt) {
				aa = i; bb = j; cnt = temp;
			}
		}
	}

	printf("%d %d\n", aa, bb);
}