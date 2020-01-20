#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1e8;
const int MAX = 2000;

int T, n, m, t, s, g, h, a, b, d, x;
int gd[MAX + 1], hd[MAX + 1], sd[MAX + 1];

vector<vector<pair<int,int>>> vt;
vector<int> res;

void func(int start, int* dist) {

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (pq.size()) {
		
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here] != INF) continue;
		dist[here] = cost;

		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int ncost = cost + vt[here][i].second;

			if (dist[there] > ncost) {
				pq.push({ -ncost, there });
			}
		}
	}
}

int main() {

	scanf("%d", &T);
	while (T--) {

		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		vt.resize(n + 1);

		int temp;

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			vt[a].push_back({ b,d });
			vt[b].push_back({ a,d });

			if (a == g && b == h) temp = d;
			if (a == h && b == g) temp = d;
		}

		func(s, sd);
		func(g, gd);
		func(h, hd);

		for (int i = 0; i < t; i++) {
			scanf("%d", &x);
			if (sd[x] == sd[g] + hd[x] + temp) {
				res.push_back(x);
			}
			if (sd[x] == sd[h] + gd[x] + temp) {
				res.push_back(x);
			}
		}

		sort(res.begin(), res.end());
		
		for (int i = 0; i < res.size(); i++) {
			printf("%d ", res[i]);
		}puts("");

		res.clear();
		vt.clear();
	}
}