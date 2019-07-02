#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 5000000;

typedef struct {
	int a, b;
} st;

int t, a, b, chk[MAX + 1][2];

int main() {

	scanf("%d %d %d", &t, &a, &b);

	queue<st> qu;

	qu.push({ 0,0 });
	chk[0][0] = chk[0][1] = 1;

	int res = 0;

	while (qu.size()) {

		int now = qu.front().a;
		int water = qu.front().b;
		qu.pop();

		res = max(res, now);

		if (now + a <= t && chk[now + a][water] == 0) {
			qu.push({ now + a,water });
			chk[now + a][water] = 1;
		}

		if (now + b <= t && chk[now + b][water] == 0) {
			qu.push({ now + b,water });
			chk[now + b][water] = 1;
		}

		if (water == 0 && chk[now / 2][1] == 0) {
			qu.push({ now / 2,1 });
			chk[now / 2][1] = 1;
		}
	}

	printf("%d\n", res);
}