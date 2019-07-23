#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, x, cost[100100], budget[100100];

int func() {

	int left = 0;
	int right = min(n, m);
	int mid, extra, flag, ret = 0;

	while (left <= right) {

		flag = 0;
		extra = x;
		mid = (left + right) / 2;
		for (int i = 0, j = m - mid; i < n && j < m; i++, j++) {
			if (cost[i] > budget[j]) {
				extra -= cost[i] - budget[j];
				if (extra < 0) {
					flag = 1; break;
				}
			}
		}

		if (flag) {
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

	scanf("%d %d %d", &n, &m, &x);

	for (int i = 0; i < n; i++) {
		scanf("%d", cost + i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", budget + i);
	}

	sort(cost, cost + n);
	sort(budget, budget + m);

	printf("%d\n", func());
}