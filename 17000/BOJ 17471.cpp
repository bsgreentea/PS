#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 123456789;

int n, population[10], visited[10], ans = INF;
int colored[10];

vector<int> vt[10];

void bfs(int start) {

	visited[start] = 1;
	
	queue<int> qu;
	qu.push(start);

	while (qu.size()) {

		int here = qu.front();
		qu.pop();

		for (auto next : vt[here]) {
			if (visited[next]) continue;
			if (colored[here] != colored[next]) continue;

			visited[next] = 1;
			qu.push(next);
		}
	}
}

void verify() {

	for (int i = 0; i < n; i++) visited[i] = 0;

	int a = 0, b = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		if (colored[i]) a++;
		else b++;

		bfs(i);
	}

	bool granted = (a == 1 && b == 1);
	
	if (!granted) return;

	int district_a = 0;
	int district_b = 0;

	for (int i = 0; i < n; i++) {
		if (colored[i]) {
			district_a += population[i];
		}
		else {
			district_b += population[i];
		}
	}

	if (district_b > district_a) {
		int diff = district_b - district_a;
		ans = min(ans, diff);
	}
	else {
		int diff = district_a - district_b;
		ans = min(ans, diff);
	}
}

void make_comb(int cnt) {

	if (cnt == n - 1) {
		verify();
		return;
	}

	colored[cnt + 1] = 1;
	make_comb(cnt + 1);
	colored[cnt + 1] = 0;
	make_comb(cnt + 1);
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", population + i);
	}

	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);

		int node;
		for (int j = 0; j < num; j++) {
			scanf("%d", &node);
			vt[i].push_back(node - 1);
			vt[node - 1].push_back(i);
		}
	}

	make_comb(-1);

	if (ans == INF) puts("-1");
	else printf("%d\n", ans);
}