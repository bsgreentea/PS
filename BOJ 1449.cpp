#include <cstdio>
#include <algorithm>
using namespace std;

int n, l, p[1010];

int main() {

	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}



	int cnt = 1;
	int s = p[0];
	for (int i = 0; i < n; i++) {
		if (p[i] - s >= l) {
			cnt++; s = p[i];
		}
	}

	printf("%d\n", cnt);
}