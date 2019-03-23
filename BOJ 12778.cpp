#include <cstdio>

int t, m, c;

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d %c\n", &m, &c);
		if (c == 'C') {
			for (int i = 0; i < m; i++) {
				scanf("%c", &c);
				getchar();
				printf("%d ", c - 'A' + 1);
			}
		}
		else {
			int a;
			for (int i = 0; i < m; i++) {
				scanf("%d", &a);
				printf("%c ", a + 'A' - 1);
			}
			getchar();
		}
		puts("");
	}
}