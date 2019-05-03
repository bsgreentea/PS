#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, height[300300], diff[300300], sum;

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", height + i);
		if (i > 1)
			diff[i] = height[i] - height[i - 1];
	}

	sum = height[n] - height[1];

	sort(diff + 1, diff + n + 1);

	for (int i = n; i >= 1; i--) {
		if (k == 1) break;
		sum -= diff[i];
		k--;
	}

	printf("%d\n", sum);
}