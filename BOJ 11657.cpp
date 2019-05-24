#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e9;

int n, m, dist[505];
vector<vector<pair<int, int>>> vt;

int main() {

	scanf("%d %d", &n, &m);
	vt.resize(n + 1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}

	dist[1] = 0;

	bool minus_cycle = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto& it : vt[j]) {
				int next = it.first;
				int d = it.second;
				if (dist[j] != MAX && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					if (i == n) minus_cycle = true;
				}
			}
		}
	}

	if (minus_cycle) puts("-1");
	else {
		for (int i = 2; i <= n; i++) {
			printf("%d\n", dist[i] != MAX ? dist[i] : -1);
		}
	}
}