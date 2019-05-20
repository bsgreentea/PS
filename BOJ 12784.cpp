#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int map[1111][1111], n, m, t;

int func(int curr, int par) {

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i == par || !map[curr][i]) continue;
		sum += func(i, curr);
	}

	if (!sum) return map[curr][par];
	return min(sum, map[curr][par]);
}

int main() {

	scanf("%d", &t);
	
	while (t--) {
		scanf("%d %d", &n, &m);

		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}
		
		map[1][0] = 1e9;

		if (!m) puts("0");
		else printf("%d\n", func(1, 0));

		memset(map, 0, sizeof(map));
	}	
}