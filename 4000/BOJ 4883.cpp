#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tc, n, map[100100][3], dp[100100][3];

int main() {
	
	while (1) {

		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		dp[0][1] = map[0][1];
		dp[0][2] = dp[0][1] + map[0][2];
		dp[1][0] = dp[0][1] + map[1][0];
		dp[1][1] = min(dp[1][0], min(dp[0][1], dp[0][2])) + map[1][1];
		dp[1][2] = min(dp[1][1], min(dp[0][1], dp[0][2])) + map[1][2];

		int a, b, c;
		for (int i = 2; i < n; i++) {
			a = dp[i - 1][0];
			b = dp[i - 1][1];
			c = dp[i - 1][2];

			dp[i][0] = min(a, b) + map[i][0];
			dp[i][1] = min(dp[i][0], min(a, min(b, c))) + map[i][1];
			dp[i][2] = min(dp[i][1], min(b, c)) + map[i][2];
		}

		printf("%d. %d\n", ++tc, dp[n - 1][1]);
	}
}

//#include <cstdio>
//
//int a, b;
//
//void func(int num) {
//
//	if (num > b) return;
//
//	func(num * 10 + 4);
//	func(num * 10 + 7);
//}
//
//int main() {
//
//	scanf("%d %d", &a, &b);
//
//
//
//}