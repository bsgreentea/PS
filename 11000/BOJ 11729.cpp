#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> vt;

void func(int level, int from, int to) {

	if (level == 0) return;
	int temp = 6 - from - to;
	
	func(level - 1, from, temp);
	vt.push_back({ from,to });
	func(level - 1, temp, to);
}

int main() {

	scanf("%d", &n);

	func(n, 1, 3);

	printf("%d\n", vt.size());
	for (int i = 0; i < vt.size(); i++) {
		printf("%d %d\n", vt[i].first, vt[i].second);
	}
}