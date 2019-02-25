#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k, m, disc[100100], tube_chk[1010];
vector<vector<int>> tube_list, tube;

int main() {

	scanf("%d %d %d", &n, &k, &m);
	tube_list.resize(n + 1);
	tube.resize(m + 1);

	int a, b, c;
	for (int i = 1; i <= m; i++) {
		b = 0;
		for (int j = 0; j < k; j++) {
			scanf("%d", &a);
			tube[i].push_back(a);
			tube_list[a].push_back(i);
		}
	}

	if (n == 1) {
		puts("1"); return 0;
	}

	queue<int> qu;
	qu.push(1);
	disc[1]++;

	int cnt = 1, flag = 0;
	while (!qu.empty()) {
		int qs = qu.size();
		while (qs--) {
			int now = qu.front();
			qu.pop();

			for (int now_tube : tube_list[now]) {
				if (tube_chk[now_tube]) continue;
				
				for (int next : tube[now_tube]) {
					if (disc[next]) continue;
				
					disc[next] = 1;

					if (next == n) {
						flag = 1; break;
					}

					if (tube_list[next].size() == 1) continue;
					qu.push(next);
				}
			}
			if (flag) break;

			for (int temp : tube_list[now]) {
				tube_chk[temp] = 1;
			}
		}
		cnt++;
		if (flag) break;
	}

	if (flag)
		printf("%d\n", cnt);
	else
		puts("-1");
}