#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<pair<int, int>> vt[1010];
priority_queue<int> dist[1010];

int main() {

	scanf("%d %d %d", &n, &m, &k);

	int	a, b, c;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
	}

	priority_queue<pair<int, int>> pq;

	pq.push({ 0,1 });
	while (pq.size()) {

		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here].size() >= k) continue;
		dist[here].push(cost);

		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int ncost = cost + vt[here][i].second;

			if (dist[there].size() < k) {
				pq.push({ -ncost, there });
			}
			else {
				if (dist[there].top() > ncost) {
					dist[there].pop();
					pq.push({ -ncost,there });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) puts("-1");
		else printf("%d\n", dist[i].top());
	}
}