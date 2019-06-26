//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//typedef double d;
//
//const d PI = 3.1415926535;
//
//int t;
//d l[1010], r[1010], h[1010], radi, s, e, res;
//
//// h is smaller than radius
//d get_dist(d height) {
//	return 2 * sqrt(2 * radi * height - height * height);
//}
//
//d get_curve(d height) {
//	return acos((radi - height) / radi) * 2 * radi;
//}
//
//int main() {
//
//	scanf("%d", &t);
//
//	int n;
//
//	for (int tc = 1; tc <= t; tc++) {
//
//		res = 0;
//
//		scanf("%lf %lf %lf", &radi, &s, &e);
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%lf %lf %lf", l + i, r + i, h + i);
//		}
//
//		res = e - s;
//		for (int i = 0; i < n; i++) {
//			if (h[i] >= radi) {
//				res += PI * radi;
//				res += 2 * (h[i] - radi);
//				res -= 2 * radi;
//			}
//			else {
//				res += get_curve(h[i]);
//				res -= get_dist(h[i]);
//			}
//		}
//
//		printf("Case #%d\n", tc);
//		printf("%.8lf\n", res);
//	}
//}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//typedef long long ll;
//
//ll t, x, y, res, tmp, cand[320000];
//
//ll get_cnt(ll target) {
//
//	if (target <= 2) return target;
//
//	ll temp = lower_bound(cand, cand + tmp, target) - cand;
//
//	if (cand[temp] == target) {
//		return temp;
//	}
//	return temp - 1 + get_cnt(target - cand[temp - 1]);
//}
//
//int main() {
//
//	for (ll i = 0; i < 320000; i++) {
//		cand[i] = i * (i + 1) / 2;
//	}
//
//	scanf("%lld", &t);
//	for (ll tc = 1; tc <= t; tc++) {
//
//		res = 0;
//
//		scanf("%lld %lld", &x, &y);
//
//		tmp = upper_bound(cand, cand+320000, y) - cand;
//
//		for (ll i = x; i <= y; i++) {
//			res = max(res, get_cnt(i));
//		}
//
//		printf("Case #%lld\n%lld\n", tc, res);
//	}
//}

