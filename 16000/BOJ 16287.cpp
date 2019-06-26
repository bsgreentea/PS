#include <cstdio>
#include <vector>
using namespace std;

int w, n, a[5050];
vector<pair<int, int>> vt[800000];

int main() {

	scanf("%d %d", &w, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] >= w) continue;
			vt[a[i] + a[j]].push_back({ i,j });
		}
	}

	int temp, flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp = a[i] + a[j];
			if (temp >= w) continue;

			for (auto elem : vt[w - temp]) {
				if (elem.first == i || elem.first == j || elem.second == i || elem.second == j) continue;
				flag = 1; break;
			}
		}
		if (flag) break;
	}

	if (flag) puts("YES");
	else puts("NO");
}