#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 32000;

int n, m, in[MAX + 1];

vector<vector<int>> vt;
priority_queue<int> pq;

int main() {

	scanf("%d %d", &n, &m);
	vt.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!in[i]) pq.push(-i);
	}

	while (pq.size()) {
		int here = -pq.top();
		pq.pop();

		printf("%d ", here);
		for (int next : vt[here]) {
			in[next]--;
			if (!in[next]) pq.push(-next);
		}
	}puts("");
}