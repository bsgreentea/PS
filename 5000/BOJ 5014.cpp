#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1000010;

int f, s, g, u, d, c[MAX];

queue<int> qu;

int main() {

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	qu.push(s);
	c[s]++;

	int cnt = 0, flag = 0;
	while (!qu.empty()) {
		int qs = qu.size();
		while (qs--) {
			int now = qu.front();
			qu.pop();

			if (now == g) {
				flag++; break;
			}

			if (now + u <= f && !c[now + u]) {
				c[now + u]++;
				qu.push(now + u);
			}
			if (now - d > 0 && !c[now - d]) {
				c[now - d]++;
				qu.push(now - d);
			}
		}
		if (flag) break;
		cnt++;
	}

	if(flag)
		printf("%d\n", cnt);
	else puts("use the stairs");
}