#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1e9;

int n, cost[20][20], p, dp[1 << 16];
char str[20];

int solve(int num, int state) {

	if (num == p) return 0;

	int& ret = dp[state];

	if (ret != -1) return ret;

	ret = MAX;

	for (int i = 0; i < n; i++) {
		if (state & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (!(state & (1 << j))) {
					ret = min(ret, solve(num + 1, state | (1 << j)) + cost[i][j]);
				}
			}
		}
	}

	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	char c;
	int now = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'Y') {
			now |= 1 << i;
			cnt++;
		}
	}

	cin >> p;

	if (cnt >= p) cout << "0\n";
	else {
		int res = solve(cnt, now);
		if (res == MAX) res = -1;
		cout << res << "\n";
	}
}