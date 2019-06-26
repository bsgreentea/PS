#include <cstdio>
#include <queue>
using namespace std;

int n, k, pick[222], depth[222];

int main() {

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", pick + i);
		depth[i] = -1;
	}

	queue<pair<int,int>> qu;
	qu.push({ 0,0 });

	while (qu.size()) {

		int now = qu.front().first;
		int dep = qu.front().second;
		qu.pop();

		int next = pick[now];
		if (depth[next] != -1) continue;

		depth[next] = dep + 1;
		qu.push({ next, dep + 1 });
	}

	printf("%d\n", depth[k]);
}