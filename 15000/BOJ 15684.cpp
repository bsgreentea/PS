#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m, h, ans = INF;
bool ladder[33][12];

bool chk() {

	for (int line = 1; line <= n; line++) {

		int start = line;
		for (int level = 1; level <= h; level++) {
			if (ladder[level][start]) start++;
			else if (ladder[level][start - 1]) start--;
		}
		if (start != line) return false;
	}
	return true;
}

void solve(int level ,int cnt) {

	if (cnt > 3) return;
	if (chk()) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = level; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
			ladder[i][j] = true;
			solve(i, cnt + 1);
			ladder[i][j] = false;
		}
	}
}

int main() {

	scanf("%d %d %d", &n, &m, &h);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		ladder[a][b] = true;
	}

	solve(1, 0);

	if (ans != INF) printf("%d\n", ans);
	else printf("-1\n");
}