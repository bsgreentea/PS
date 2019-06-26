#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 32000;

int n, m, visited[MAX + 1];

vector<vector<int>> vt;

stack<int> st;

void dfs(int here) {

	visited[here] = 1;
	for (int next : vt[here]) {
		if (visited[next]) continue;
		dfs(next);
	}
	st.push(here);
}

int main() {

	scanf("%d %d", &n, &m);
	vt.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs(i);
	}

	while (st.size()) {
		printf("%d ", st.top());
		st.pop();
	}puts("");
}