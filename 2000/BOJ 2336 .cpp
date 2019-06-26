#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 987654321;

int n;
vector<int> tree;
vector<pair<int, pair<int, int>>> vt;

int update(int pos, int val, int node, int start, int end) {

	if (pos < start || end < pos)
		return tree[node];

	if (start == end) return tree[node] = val;
	
	int mid = (start + end) / 2;
	return tree[node] = min(update(pos, val, node * 2, start, mid), update(pos, val, node * 2 + 1, mid + 1, end));
}

int query(int lo, int hi, int node, int start, int end) {
	
	if (end < lo || hi < start)
		return INF;

	if (lo <= start && end <= hi)
		return tree[node];

	int mid = (start + end) / 2;
	return min(query(lo, hi, node * 2, start, mid), query(lo, hi, node * 2 + 1, mid + 1, end));
}

int main() {

	scanf("%d", &n);
	vt.resize(n + 1);

	int h = (int)ceil(log2(n + 1));
	int ts = (1 << (h+1));
	tree.assign(ts, INF);

	int num;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		vt[num].first = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		vt[num].second.first = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		vt[num].second.second = i;
	}

	sort(vt.begin(), vt.end());

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (query(1, vt[i].second.first, 1, 1, n) > vt[i].second.second) {
			cnt++;
		}
		update(vt[i].second.first, vt[i].second.second, 1, 1, n);
	}
	
	printf("%d\n", cnt);
}