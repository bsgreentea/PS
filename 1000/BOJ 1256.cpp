#include <cstdio>

typedef unsigned long long ll;

ll n, m, k, dp[222][222], res[222];

int main() {

	scanf("%llu %llu %llu", &n, &m, &k);

	for (ll i = 1; i <= n + m; i++) {
		for (ll j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = 1;
			else if (j == 1) dp[i][j] = i;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	if (dp[n + m][n] < k) {
		puts("-1"); return 0;
	}

	ll nn = n, mm = m;

	ll idx = 0, cnt = 0;
	while (1) {

		ll temp = n * dp[n + m][n] / (n + m);

		if (k <= temp) {
			res[idx] = 1;
			cnt++;
			n--;
		}
		else {
			m--;
			k -= temp;
		}

		idx++;
		if (idx == mm + nn) break;
	}

	for (ll i = 0; i < nn + mm; i++) {
		printf("%c", res[i] ? 'a' : 'z');
	}puts("");
}