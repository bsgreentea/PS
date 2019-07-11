#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<int> input, tree;

int init(int node ,int start, int end) {

	if (start == end) 
		return tree[node] = input[start];

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int update(int pos, int val, int node, int start, int end) {

	if (pos < start || end < pos) return tree[node];
	if (start == end) return tree[node] += val;

	int mid = (start + end) / 2;
	return tree[node] = update(pos, val, node * 2, start, mid) + update(pos, val, node * 2 + 1, mid + 1, end);
}

int query(int target, int node, int start, int end) {

	if (start == end) return start;

	int mid = (start + end) / 2;

	if (tree[node * 2] >= target)
		return query(target, node * 2, start, mid);
	return query(target - tree[node * 2], node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%d", &n);
	input.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}

	int h = (int)ceil(log2(n + 1));
	int ts = 1 << (h + 1);

	tree.resize(ts);
	init(1, 1, n);

	scanf("%d", &m);

	int a, b, c;
	while (m--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d", &b, &c);
			update(b, c, 1, 1, n);
		}
		else {
			scanf("%d", &b);
			printf("%d\n", query(b, 1, 1, n));
		}
	}
}