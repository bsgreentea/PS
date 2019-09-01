#include <cstdio>
#include <algorithm>
using namespace std;

int d, n, m, a[50005];

int solve() {

	int ret = d;
	int left = 0, right = d, res = 0, mid;

	while (left <= right) {

		mid = (left + right) / 2;

		int start = 0, cnt = 0;

		for (int i = 0; i <= n; i++) {

			if (a[i] - start < mid) {
				cnt++;
			}
			else {
				start = a[i];
			}
		}

		if (cnt > m) {
			right = mid - 1;
		}
		else {
			ret = mid;
			left = mid + 1;
		}
	}

	return ret;
}

int main() {

	scanf("%d %d %d", &d, &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}

	sort(a, a + n);
	a[n] = d;

	printf("%d\n", solve());
}