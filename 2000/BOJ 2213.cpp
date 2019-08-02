#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, num[10001], dp[10001][2];

vector<int> vt[10001], res;

int func(int now, int par, int chk) {

	int& ret = dp[now][chk];
	if (ret != -1) return ret;

	if (chk) ret = num[now];
	else ret = 0;

	for (int i = 0; i < vt[now].size(); i++) {
		int next = vt[now][i];
		if (next == par) continue;

		if (chk)
			ret += func(next, now, 0);
		else
			ret += max(func(next, now, 0), func(next, now, 1));
	}

	return ret;
}

void find_res(int now, int par, int chk) {

	if (chk) {
		res.push_back(now);
		for (int i = 0; i < vt[now].size(); i++) {
			int next = vt[now][i];
			if (next == par) continue;
			find_res(next, now, 0);
		}
	}
	else {
		for (int i = 0; i < vt[now].size(); i++) {
			int next = vt[now][i];
			if (next == par) continue;
			if (dp[next][1] > dp[next][0]) find_res(next, now, 1);
			else find_res(next, now, 0);
		}
	}
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", num + i);

	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	int tmp1 = func(1, 0, 0);
	int tmp2 = func(1, 0, 1);

	if (tmp1 > tmp2)
		find_res(1, 0, 0);
	else
		find_res(1, 0, 1);

	sort(res.begin(), res.end());

	printf("%d\n", max(tmp1, tmp2));

	for (int e : res) printf("%d ", e);
	puts("");
}