#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, dp[100100];
vector<int> coin;

const int INF = 1e9 + 10;

int func(int num) {

	if (num < 1) return INF;

	int& ret = dp[num];

	if (ret) return ret;
	else ret = INF;

	for (int i = 0; i < coin.size(); i++) {
		ret = min(ret, func(num - coin[i]) + func(coin[i]));
	}

	return ret;
}

int main() {

	scanf("%d %d", &n, &k);

	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a > k) continue;
		coin.push_back(a);
		dp[a] = 1;
	}

	sort(coin.begin(), coin.end());

	int res = func(k);

	if (res == INF) puts("-1");
	else printf("%d\n", res);
}