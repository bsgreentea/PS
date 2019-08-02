#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1e6;

int n, dp[MAX + 1][2];

vector<int> vt[MAX + 1];

int func(int now, int par, int chk) {

	if (vt[now].size() == 1 && par) {
		if (chk) return 1;
		else return 0;
	}

	int& ret = dp[now][chk];

	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < vt[now].size(); i++) {
		int next = vt[now][i];
		if (next == par) continue;

		if (chk) ret += min(func(next, now, 1), func(next, now, 0));
		else ret += func(next, now, 1);
	}

	if (chk) ret++;
	return ret;
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);

	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	printf("%d\n", min(func(1, 0, 0), func(1, 0, 1)));
}