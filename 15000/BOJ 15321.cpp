#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const ll INF = 1e18;

ll n, power[505];
p dp[505][505];

p func(ll left, ll right) {

	if (left == right) return{ 0, left };
	if (left + 1 == right)
		return{ (ll)abs(power[left] - power[right]), power[left] > power[right] ? left : right };

	p& ret = dp[left][right];
	if (ret.first != -1) return ret;

	ret.first = INF;

	p temp1, temp2;
	for (ll i = left; i < right; i++) {

		temp1 = func(left, i);
		temp2 = func(i + 1, right);

		ll boreness = temp1.first + temp2.first + (ll)abs(power[temp1.second] - power[temp2.second]);
		if (ret.first > boreness) {
			ret = { boreness, power[temp1.second] > power[temp2.second] ? temp1.second : temp2.second };
		}
	}

	return ret;
}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", power + i);
	}

	printf("%lld\n", func(1, n).first);
}