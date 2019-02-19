#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, m, x, y, disc[111];
vector<vector<int>> vt;

int main() {

	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);

	vt.resize(n + 1);

	while (m--) {
		scanf("%d %d", &x, &y);
		vt[x].push_back(y);
		vt[y].push_back(x);
	}

	queue<int> qu;
	qu.push(a);

	disc[a] = 1;

	int cnt = 0, flag = 0;
	while (qu.size()) {
		int qs = qu.size();
		while (qs--) {
			int here = qu.front();
			qu.pop();

			for (int there : vt[here]) {
				if (disc[there]) continue;
				qu.push(there);
				disc[there] = 1;

				if (there == b) {
					flag++; break;
				}
			}
			if (flag) break;
		}
		cnt++;
		if (flag) break;
	}
	if(flag)
		printf("%d\n", cnt);
	else puts("-1");
}