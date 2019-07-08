#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 200000;

int n, m, par[MAX + 1], chk[MAX + 1], query[MAX + 1], res[MAX + 1];
vector<int> vt[MAX + 1];

int Find(int curr) {
	if (curr == par[curr]) return curr;
	return par[curr] = Find(par[curr]);
}

bool Merge(int a, int b) {

	a = Find(a); b = Find(b);
	if (a == b) return false;

	par[a] = b;
	return true;
}

int main() {

	scanf("%d %d", &n, &m);
	
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &query[n - i - 1]);
	}

	for (int i = 1; i <= n; i++)
		par[i] = i;

	int now, g = 0;
	for (int i = 0; i < n; i++) {
		now = query[i];

		g++;

		int temp;
		for (int j = 0; j < vt[now].size(); j++) {
			temp = vt[now][j];
			if (chk[temp] && Merge(now, temp)) {
				g--;
			}
		}
		if (g == 1) res[i]++;
		chk[now]++;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (res[i]) puts("YES");
		else puts("NO");
	}
}