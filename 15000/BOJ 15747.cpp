#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;

int n, a[101], dp[101][101][101];

int func(int idx, int breakout, int last) {

	if (idx == 1) {
		if (breakout == 1) return a[idx] != 0;
		else return INF;
	}
	if (last > idx - breakout) return INF;
	if (breakout > idx)  return INF;

	int& ret = dp[idx][breakout][last];

	if (ret != -1) return ret;

	ret = INF;

	if (last == 0) {
		for (int i = idx - breakout; i >= 0; i--)
			ret = min(ret, func(idx - 1, breakout - 1, i) + (a[idx] != 0));
	}
	else {
		ret = min(ret, func(idx - 1, breakout, last - 1) + (a[idx] != last));
	}

	return ret;
}

int main() {
	
	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}

	for (int i = 1; i <= n; i++) {
		int ans = INF;
		for (int j = 0; j <= n - i; j++) {
			ans = min(ans, func(n, i, j));
		}
		printf("%d\n", ans);
	}
}