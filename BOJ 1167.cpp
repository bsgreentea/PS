#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1e5;

int n, dist[MAX + 1], disc[MAX + 1];
vector<pair<int, int>> vt[MAX + 1];

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
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		while (1) {
			scanf("%d", &b);
			if (b == -1) break;

			scanf("%d", &c);
			vt[a].push_back({ b, c });
		}
	}

	int s, e;
	s = find_farthest(1);

	memset(dist, 0, sizeof(dist));
	memset(disc, 0, sizeof(disc));

	e = find_farthest(s);

	printf("%d\n", dist[e]);
}