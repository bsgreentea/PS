#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, dist[10010], disc[10010];
vector<pair<int, int>> vt[10010];

int find_farthest(int start) {

	int ret = 0, maxd = 0;

	queue<pair<int, int>> qu;
	qu.push({ start, 0 });
	disc[start] = 1;

	while (qu.size()) {

		int now = qu.front().first;
		int cost = qu.front().second;
		qu.pop();

		dist[now] = cost;
		if (cost > maxd) {
			maxd = cost;
			ret = now;
		}

		for (int i = 0; i < vt[now].size(); i++) {
			int next = vt[now][i].first;
			int temp = vt[now][i].second;

			if (disc[next]) continue;

			disc[next]++;
			qu.push({ next, cost + temp });
		}
	}

	return ret;
}

int main() {

	scanf("%d", &n);

	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}

	int s, e;
	s = find_farthest(1);

	memset(dist, 0, sizeof(dist));
	memset(disc, 0, sizeof(disc));

	e = find_farthest(s);

	printf("%d\n", dist[e]);
}