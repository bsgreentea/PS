#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

int n, k, dp[MAX + 2][3][22];
int john[MAX + 2];

int func(int round, int state, int change) {

	if (round == 0) return 0;

	int& ret = dp[round][state][change];

	if (ret != -1) return ret;

	ret = (john[round] == (state + 1) % 3);

	int t1, t2;
	t1 = t2 = 0;
	if (change > 0) {
		t1 = func(round - 1, (state + 1) % 3, change - 1);
		t1 = max(t1, func(round - 1, (state + 2) % 3, change - 1));
	}
	t2 = func(round - 1, state, change);
	
	return ret += max(t1, t2);
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &k);

	char c; int a;
	for (int i = 1; i <= n; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'H') a = 0;
		else if (c == 'S') a = 1;
		else a = 2;
		john[i] = a;
	}

	for (int i = 0; i < 3; i++) {
		dp[1][i][0] = john[1] == (i + 1) % 3 ? 1 : 0;
	}

	int res = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 3; j++) {
			res = max(res, func(n, j, i));
		}
	}

	printf("%d\n", res);
}