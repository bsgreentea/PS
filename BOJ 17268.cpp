#include <cstdio>

typedef long long ll;

const ll MOD = 987654321;

ll n, dp[10101];

ll solve(ll num) {

	if (num == 0 || num == 2) return dp[num] = 1;

	if (dp[num]) return dp[num];

	ll ret = 0;

	for (ll i = 0; i < num; i += 2) {
		ret += (solve(i) % MOD)*(solve(num - i - 2) % MOD);
		ret %= MOD;
	}

	return dp[num] = ret % MOD;
}

int main() {

	scanf("%lld", &n);

	printf("%lld\n", solve(n));
}