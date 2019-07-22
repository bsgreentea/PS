#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll t, n;

ll func() {

	ll left = 1;
	ll right = 1e9;

	ll mid, ret = 0;

	while (left <= right) {

		mid = (left + right) / 2;

		if (mid * (1 + mid) / 2 <= n) {
			left = mid + 1;
			ret = max(ret, mid);
		}
		else {
			right = mid - 1;
		}

	}

	return ret;
}

int main() {

	scanf("%lld", &t);
	while (t--) {

		scanf("%lld", &n);
		printf("%lld\n", func());
	}

}