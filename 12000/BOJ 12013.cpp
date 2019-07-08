#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, dp[250][250], num[250];

int func(int a, int b) {

	if (a == b) return num[a];

	int& ret = dp[a][b];

	if (ret != -1) return ret;
	ret = 0;

	for (int i = a; i <= b; i++) {
		int x = func(a, i);
		int y = func(i + 1, b);
		if (x == y)
			ret = max(ret, x + 1);
	}

	return ret;
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", num + i);
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			res = max(res, func(i, j));
		}
	}

	printf("%d\n", res);
}