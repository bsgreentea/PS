#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 500000;

int n, k, chk[MAX + 1];
queue<int> qu;

int main() {

	scanf("%d %d", &k, &n);

	if (n == k) {
		puts("0"); return 0;
	}

	qu.push(k);
	
	int flag = 0, cnt = 0, inc = 0;

	while (!qu.empty()) {

		inc++;
		n += inc;
		if (n > MAX) break;

		int qs = qu.size();
		
		while (qs--) {

			int here = qu.front();
			qu.pop();

			if (here + 1 >= 0 && here + 1 <= MAX) {
				if (here + 1 == n) {
					flag = 1; break;
				}
				if (!chk[here + 1]) {
					qu.push(here + 1);
					chk[here + 1]++;
				}
			}
			if (here - 1 >= 0 && here - 1 <= MAX) {
				if (here - 1 == n) {
					flag = 1; break;
				}
				if (!chk[here - 1]) {
					qu.push(here - 1);
					chk[here - 1]++;
				}
			}
			if (here * 2 >= 0 && here * 2 <= MAX) {
				if (here * 2 == n) {
					flag = 1; break;
				}
				if (!chk[here * 2]) {
					qu.push(here * 2);
					chk[here * 2]++;
				}
			}
		}
		memset(chk, 0, sizeof(chk));
		cnt++;
		if (flag) break;
	}

	if (flag) printf("%d\n", cnt);
	else puts("-1");
}