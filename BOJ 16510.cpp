#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, num[200200], psum[200200];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", num + i);
		psum[i] = num[i] + psum[i - 1];
	}

	int a;
	while (m--) {
		scanf("%d", &a);
		printf("%d\n", upper_bound(psum + 1, psum + n + 1, a) - (psum + 1));
	}
}