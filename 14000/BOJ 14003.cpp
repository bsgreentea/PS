#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9 + 10;

int n, num[1000100], pre[1000100];
vector<int> res, vt, idx;

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", num + i);
	}

	int last;
	vt.push_back(-INF);
	idx.push_back(-1);
	for (int i = 1; i <= n; i++) {

		if (num[i] > vt.back()) {

			pre[i] = idx.back();

			vt.push_back(num[i]);
			idx.push_back(i);
			last = i;
		}
		else {
			int it = lower_bound(vt.begin(), vt.end(), num[i]) - vt.begin();

			vt[it] = num[i];
			idx[it] = i;
			pre[i] = idx[it - 1];
		}

	}

	printf("%d\n", vt.size() - 1);
	int cnt = vt.size() - 1;
	while (cnt--) {
		res.push_back(num[last]);
		last = pre[last];
	}

	for (int i = res.size() - 1; i >= 0; i--) {
		printf("%d ", res[i]);
	}puts("");
}