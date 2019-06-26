#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, t, a, b, disc[100100][2];

vector<vector<int>> vt1, vt2;

void bfs(vector<vector<int>>& vt, int start, int chk) {

	queue<int> qu;
	qu.push(start);

	while (qu.size()) {
		int here = qu.front();
		qu.pop();
		for (int i = 0; i < vt[here].size(); i++) {
			int next = vt[here][i];
			if (disc[next][chk]) continue;
			qu.push(next);
			disc[next][chk]++;
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);

	vt1.resize(n + 1);
	vt2.resize(n + 1);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt1[a].push_back(b);
		vt2[b].push_back(a);
	}

	bfs(vt1, 1, 0);
	bfs(vt2, n, 1);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &a);
		if (disc[a][0] && disc[a][1])
			puts("Defend the CTP");
		else puts("Destroyed the CTP");
	}
}