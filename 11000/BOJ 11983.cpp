//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <utility>
//#include <vector>
//
//#define f first
//#define s second
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<ll, ll> p;
//
//const ll MAX = 1e18;
//
//ll n, m, dp[1010][1010];
//char a[1010], b[1010];
//
//p x, y;
//vector<p> vt1, vt2;
//
//ll get_dist(ll i, ll j) {
//	return (vt1[i].f - vt2[j].f)*(vt1[i].f - vt2[j].f) + (vt1[i].s - vt2[j].s)*(vt1[i].s - vt2[j].s);
//}
//
//ll func(ll num1, ll num2) {
//
//	if (num1 < 0 || num2 < 0) return MAX;
//	if (num1 + num2 == 0) return 0;
//
//	ll& ret = dp[num1][num2];
//
//	if (ret != -1) return ret;
//
//	ll temp1 = MAX;
//	temp1 = min(temp1, func(num1 - 1, num2));
//	temp1 = min(temp1, func(num1, num2 - 1));
//
//	temp1 += get_dist(num1, num2);
//
//	ll temp2 = func(num1 - 1, num2 - 1) + get_dist(num1, num2);
//
//	return ret = min(temp1, temp2);
//}
//
//int main() {
//
//	for (ll i = 0; i < 1010; i++) {
//		for (ll j = 0; j < 1010; j++) {
//			dp[i][j] = -1;
//		}
//	}
//
//	scanf("%lld %lld", &n, &m);
//	scanf("%lld %lld %lld %lld", &x.first, &x.second, &y.first, &y.second);
//
//	scanf("%s", a);
//	scanf("%s", b);
//
//	ll aa, bb;
//	aa = x.first, bb = x.second;
//	vt1.push_back({ aa,bb });
//	for (ll i = 0; i < n; i++) {
//		if (a[i] == 'N') bb++;
//		else if (a[i] == 'S') bb--;
//		else if (a[i] == 'W') aa--;
//		else aa++;
//		vt1.push_back({ aa,bb });
//	}
//
//	aa = y.first, bb = y.second;
//	vt2.push_back({ aa,bb });
//	for (ll i = 0; i < m; i++) {
//		if (b[i] == 'N') bb++;
//		else if (b[i] == 'S') bb--;
//		else if (b[i] == 'W') aa--;
//		else aa++;
//		vt2.push_back({ aa,bb });
//	}
//
//	printf("%lld\n", func(n, m));
//}