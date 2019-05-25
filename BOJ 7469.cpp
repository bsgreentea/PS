#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int n, m, input[MAX + 1];

vector<int> bucket[MAX * 2 + 1];

void update(int bucket_num, int node, int start, int end, int x) {

	if (node < start || end < node) return;
	bucket[bucket_num].push_back(x);

	int mid = (start + end) / 2;
	if (start != end) {
		update(bucket_num * 2, node, start, mid, x);
		update(bucket_num * 2 + 1, node, mid + 1, end, x);
	}
}

int query(int bucket_num, int start, int end, int left, int right, int x) {

	if (right < start || end < left) return 0;
	if (left <= start && end <= right)
		return upper_bound(bucket[bucket_num].begin(), bucket[bucket_num].end(), x) - bucket[bucket_num].begin();

	int mid = (start + end) / 2;
	return query(bucket_num * 2, start, mid, left, right, x) + query(bucket_num * 2 + 1, mid + 1, end, left, right, x);

}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", input + i);
		update(1, i, 1, n, input[i]);
	}

	for (int i = 1; i <= MAX * 2; i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}

	int a, b, c;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		int left = -1e9, right = 1e9;
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;
			if (query(1, 1, n, a, b, mid) < c) left = mid + 1;
			else right = mid - 1;
		}
		printf("%d\n", left);
	}
}