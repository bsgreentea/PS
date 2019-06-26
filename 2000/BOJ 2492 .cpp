#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m, t, k;
vector<pair<int, int>> dia, cand;

int main() {

	scanf("%d %d %d %d", &n, &m, &t, &k);

	int x, y;
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		dia.push_back({ x,y });
	}

	for (int i = 0; i < dia.size(); i++) {
		for (int j = 0; j < dia.size(); j++) {
			
			int minx = min(dia[i].first, dia[j].first);
			int maxy = max(dia[i].second, dia[j].second);

			cand.push_back({ minx,maxy });
		}
	}

	int cnt = 0, res = 0;
	pair<int, int> ans;

	for (int i = 0; i < cand.size(); i++) {
		cnt = 0;
		int ax = cand[i].first;
		int ay = cand[i].second;

		for (int j = 0; j < dia.size(); j++) {
			int bx = dia[j].first;
			int by = dia[j].second;

			if (bx < ax || ay < by) continue;
			if (bx - ax > k || ay - by > k) continue;
			cnt++;
		}

		if (ay < k) ay = k;
		if (n - k < ax) ax = n - k;

		if (cnt >= res) {
			res = cnt;
			ans = { ax,ay };
		}
	}

	printf("%d %d\n", ans.first, ans.second);
	printf("%d\n", res);
}