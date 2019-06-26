#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> vt, diff;

int main() {

	scanf("%d %d", &n, &k);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		vt.push_back(a);
	}

	vt.erase(unique(vt.begin(), vt.end()), vt.end());

	sort(vt.begin(), vt.end());

	for (int i = 0; i < vt.size() - 1; i++) {
		diff.push_back(vt[i] - vt[i + 1]);
	}

	int res = vt.back() - vt[0];
	if (vt.size() <= k) res = 0;
	else {
		sort(diff.begin(), diff.end());
		for (int i = 0; i < diff.size(); i++) {
			if (k == i + 1) break;
			res += diff[i];
		}
	}

	printf("%d\n", max(res,0));
}