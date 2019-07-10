//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int n;
//vector<int> input, l_tree, r_tree, zip, L, R;
//
//int get_idx(vector<int>& vt, int target) {
//	return lower_bound(vt.begin(), vt.end(), target) - vt.begin();
//}
//
//int update(vector<int>& tree, int pos, int node, int start, int end) {
//
//	if (pos < start || end < pos)
//		return tree[node];
//	if (start == end)
//		return tree[node] = 1;
//
//	int mid = (start + end) / 2;
//	return tree[node] = update(tree, pos, node * 2, start, mid) + update(tree, pos, node * 2 + 1, mid + 1, end);
//}
//
//int query(vector<int>& tree, int left, int right, int node, int start, int end) {
//
//	if (right < start || end < left) return 0;
//	if (left <= start && end <= right) return tree[node];
//
//	int mid = (start + end) / 2;
//	return query(tree, left, right, node * 2, start, mid) + query(tree, left, right, node * 2 + 1, mid + 1, end);
//}
//
//int main() {
//
//	scanf("%d", &n);
//	
//	L.resize(n);
//	R.resize(n);
//
//	input.resize(n);
//	zip.resize(n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &input[i]);
//		zip[i] = input[i];
//	}
//
//	sort(zip.begin(), zip.end());
//
//	int h = (int)ceil(log2(n + 1));
//	int ts = 1 << (h + 1);
//
//	l_tree.resize(ts);
//	r_tree.resize(ts);
//
//	int target;
//	for (int i = 0; i < n; i++) {
//
//		target = get_idx(zip, input[i]);
//		update(l_tree, target, 1, 1, n);
//		L[i] = query(l_tree, 1, n, 1, 1, n) - query(l_tree, 1, target, 1, 1, n);
//
//		target = get_idx(zip, input[n - i - 1]);
//		update(r_tree, target, 1, 1, n);
//		R[n -i -1] = query(r_tree, 1, n, 1, 1, n) - query(r_tree, 1, target, 1, 1, n);
//	}
//
//	int cnt = 0, a, b;
//	for (int i = 0; i < n; i++) {
//		a = L[i]; b = R[i];
//		if (a > b) swap(a, b);
//		cnt += b > a * 2 ? 1 : 0;
//	}
//
//	printf("%d\n", cnt);
//}