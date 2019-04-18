#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, m, dist[1010];
vector<vector<pair<int, int>>> vt;
vector<pair<int, int>> res;
priority_queue<pair<int, pair<int, int>>> pq;

int main() {

	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}

	memset(dist, -1, sizeof(dist));

	pq.push({ 0,{1,0} });
	while (pq.size()) {
		int here = pq.top().second.first;
		int pre = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here] != -1) continue;
		dist[here] = cost;

		if (pre) res.push_back({ pre,here });

		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int ncost = vt[here][i].second + cost;
			
			if (dist[there] == -1) {
				pq.push({ -ncost,{there,here} });
			}
		}
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d %d\n", res[i].first, res[i].second);
	}

}