#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, chk[1010][1010], psum[1010][1010];
vector<pair<int, int>> vt;
vector<int> x, y;

int get_idx(vector<int>& vt, int num) {
	return lower_bound(vt.begin(), vt.end(), num) - vt.begin();
}

int calc(int a, int b, int c, int d) {
	return psum[c][d] - psum[c][b] - psum[a][d] + psum[a][b];
}

int main() {

	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		vt.push_back({ a,b });
		x.push_back(a);
		y.push_back(b);
	}

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());

	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	for (int i = 0; i < n; i++) {
		int tx = vt[i].first;
		int ty = vt[i].second;
		chk[get_idx(x, tx)][get_idx(y, ty)]++;
	}

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + chk[i][j];
		}
	}

	int res = n;
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			int temp = max(calc(0, 0, i, j), calc(i, j, x.size(), y.size()));
			temp = max(temp, calc(0, j, i, y.size()));
			temp = max(temp, calc(i, 0, x.size(), j));

			res = min(temp, res);
		}
	}

	printf("%d\n", res);
}