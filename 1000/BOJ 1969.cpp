#include <cstdio>

int n, m, dna[55][55], maxn[55];

int main() {

	scanf("%d %d", &n, &m);
	char c;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &c);
			dna[j][c - 'A']++;
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < 26; i++) {
			maxn[j] = maxn[j] > dna[j][i] ? maxn[j] : dna[j][i];
		}
	}

	int res = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < 26; i++) {
			if (maxn[j] == dna[j][i]) {
				printf("%c", i + 'A');
				res += n - dna[j][i];
				break;
			}
		}
	}

	printf("\n%d\n", res);
}