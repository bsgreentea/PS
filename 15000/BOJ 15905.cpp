#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> vt;

int main() {

	scanf("%d", &n);

	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		vt.push_back({ -a,b });
	}

	sort(vt.begin(), vt.end());

	int cnt = 0;
	for (int i = 5; i < vt.size(); i++) {
		if (vt[i].first == vt[4].first) cnt++;
	}

	printf("%d\n", cnt);
}