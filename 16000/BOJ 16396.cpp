#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y;
vector<pair<int, int>> vt;

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (x > y) swap(x, y);
		vt.push_back({ x,y });
	}

	sort(vt.begin(), vt.end());

	int left = vt[0].first;
	int right = vt[0].second;
	int res = right - left;
	for (int i = 1; i < vt.size(); i++) {

		int nleft = vt[i].first;
		int nright = vt[i].second;
		if (nright <= right) continue;
		if (nleft > right) {
			left = nleft;
			res += nright - left;
		}
		else {
			res += nright - right;
		}
		right = max(right, nright);
	}
	printf("%d\n", res);
}