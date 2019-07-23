#include <cstdio>

typedef long long ll;

const int MAX = 500000;

int n, tree[MAX * 4 + 1], get_idx[MAX * 2 + 10];

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

	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		get_idx[a] = i;
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		sum += query(get_idx[a], n, 1, 1, n);
		update(get_idx[a], 1, 1, n);
	}

	printf("%lld\n", sum);
}