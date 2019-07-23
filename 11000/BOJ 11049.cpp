#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

ll n, r[505], c[505], dp[505][505];

ll func(ll left, ll right) {

	if (left == right) return 0;
	if (left + 1 == right) return r[left] * r[right] * c[right];

	ll& ret = dp[left][right];

	if (ret != -1) return ret;
	ret = INF;

	for (ll i = left; i < right; i++) {
		ret = min(ret, func(left, i) + func(i + 1, right) + r[left] * r[i + 1] * c[right]);
	}

	return ret;
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", r + i, c + i);
	}

	printf("%lld\n", func(1, n));
}