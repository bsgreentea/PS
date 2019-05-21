#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 5000;

int n, m, scc_size, cnt, scc_num[MAX + 1], disc[MAX + 1];
int out[MAX + 1], in[MAX + 1];

vector<vector<int>> graph;
stack<int> st;

int dfs(int here) {

	disc[here] = ++cnt;
	st.push(here);
	int ret = disc[here];

	for (int next : graph[here]) {
		if (!disc[next]) {
			ret = min(ret, dfs(next));
		}
		else if (!scc_num[next]) {
			ret = min(ret, disc[next]);
		}
	}

	if (ret == disc[here]) {
		scc_size++;
		while (1) {
			int v = st.top();
			st.pop();
			scc_num[v] = scc_size;
			if (v == here) break;
		}
	}
	return ret;
}

void init() {
	memset(disc, 0, sizeof(disc));
	memset(scc_num, 0, sizeof(scc_num));
	memset(out, 0, sizeof(out));
	scc_size = cnt = 0;
	graph.clear();
}

int main() {

	while (1) {

		scanf("%d", &n);
		if (n == 0) break;
		scanf("%d", &m);

		graph.resize(n + 1);
		
		int v, w;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			graph[v].push_back(w);
		}

		for (int i = 1; i <= n; i++) {
			if (disc[i] == 0) dfs(i);
		}

		vector<int> res;

		for (int i = 1; i <= n; i++) {
			for (int next : graph[i]) {
				if (scc_num[i] != scc_num[next]) {
					out[scc_num[i]]++;
					in[scc_num[next]]++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (out[scc_num[i]] == 0) {
				res.push_back(i);
			}
		}

		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			printf("%d ", res[i]);
		}puts("");

		init();
	}
}