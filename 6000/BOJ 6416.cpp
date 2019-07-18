#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 1e5;

int a, b, k, in[MAX + 1], visited[MAX + 1];
vector<int> vt[MAX + 1];
set<int> st;

int flag, cnt;

void dfs(int par, int here) {

	if (visited[here]) {
		flag = 1;
		return;
	}

	visited[here]++;
	cnt++;

	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		dfs(here, there);
	}

	return;
}

int main() {

	while (1) {
		scanf("%d %d", &a, &b);
		if (a < 0 && b < 0) break;

		if (a + b == 0) {

			int chk = 0;
			for (auto it = st.begin(); it != st.end(); it++) {
				if (in[*it] == 0) {
					chk++;
					dfs(0, *it);
					if (cnt != st.size()) flag = 1;
				}
			}

			k++;
			if (st.size() == 0) flag = 0, chk = 1;

			printf("Case %d is ", k);
			if (flag || chk != 1)
				printf("not a tree.\n");
			else printf("a tree.\n");

			for (int i = 0; i < MAX + 1; i++) vt[i].clear();
			flag = 0;
			cnt = 0;
			memset(visited, 0, sizeof(visited));
			memset(in, 0, sizeof(in));
			st.clear();
			continue;
		}

		st.insert(a);
		st.insert(b);

		vt[a].push_back(b);
		in[b]++;
		if (in[b] > 1) flag = 1;
	}
}