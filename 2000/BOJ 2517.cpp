#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 500000;

int n, tree[4 * MAX + 1], res[MAX + 1];
vector<pair<int, int>> vt;

int update(int pos, int node, int start, int end) {

	if (pos < start || end < pos) return tree[node];
	if (start == end) return tree[node] = 1;

	int mid = (start + end) / 2;
	return tree[node] = update(pos, node * 2, start, mid) + update(pos, node * 2 + 1, mid + 1, end);
}

int query(int left, int right, int node, int start, int end) {

	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {
	
	scanf("%d", &n);
	vt.resize(n);

	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		vt[i] = { a,i + 1 };
	}

	sort(vt.begin(), vt.end());
	reverse(vt.begin(), vt.end());

	for (int i = 0; i < n; i++) {
		res[vt[i].second] = query(1, vt[i].second, 1, 1, n) + 1;
		update(vt[i].second, 1, 1, n);
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", res[i]);
}