#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, a[10001], dp[10001];

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}

	for (int i = 1; i <= n; i++) {
		int temp = a[i];
		for (int j = 0; j < k; j++) {
			if (i + j > n) break;
			temp = max(temp, a[i + j]);
			dp[i + j] = max(dp[i + j], dp[i - 1] + temp * (j + 1));
		}
	}

	printf("%d\n", dp[n]);
}