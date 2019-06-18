#include <cstdio>
#include <cstring>
using namespace std;

int n, m, num[2020], a, b, dp[2020][2020];

int func(int s, int e) {

	if (s == e) return 1;
	if (s + 1 == e && num[s] == num[e]) return 1;

	int& ret = dp[s][e];

	if (ret != -1) return ret;
	
	return ret = func(s + 1, e - 1)*(num[s] == num[e]);
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", num + i);
		dp[i][i] = 1;
		if (num[i] == num[i - 1]) dp[i - 1][i] = 1;
		else dp[i - 1][1] = 0;
	}

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", func(a,b));
	}
}