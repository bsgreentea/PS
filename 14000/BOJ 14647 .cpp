#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, map[555][555], tot;

int cnt9(int num) {

	int res = 0;
	while (1) {
		if (num % 10 == 9) res++;
		num /= 10;
		if (num == 0) break;
	}
	return res;
}

int batting() {

	int res = 0;
	int r, c;
	for (int i = 0; i < n; i++) {
		r = 0;
		for (int j = 0; j < m; j++) {
			r += map[i][j];
		}
		res = max(res, r);
	}

	for (int i = 0; i < m; i++) {
		c = 0;
		for (int j = 0; j < n; j++) {
			c += map[j][i];
		}
		res = max(res, c);
	}

	return res;
}

int main() {
	
	scanf("%d %d", &n, &m);
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &num);

			map[i][j] = cnt9(num);
			tot += map[i][j];
		}
	}
	
	printf("%d\n", tot - batting());
}