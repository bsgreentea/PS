#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int n, m, input[MAX + 1];

vector<int> bucket[MAX * 2 + 1];

void init(int bucket_num, int start, int end) {

	if (start == end) {
		bucket[bucket_num].push_back(input[start]);
		return;
	}

	int mid = (start + end) / 2;
	init(bucket_num * 2, start, mid);
	init(bucket_num * 2 + 1, mid + 1, end);

	auto& left = bucket[bucket_num * 2];
	auto& right = bucket[bucket_num * 2 + 1];

	merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(bucket[bucket_num]));
}

//void update(int bucket_num, int node, int start, int end, int x) {
//
//	if (node < start || end < node) return;
//	bucket[bucket_num].push_back(x);
//	
//	int mid = (start + end) / 2;
//	if (start != end) {
//		update(bucket_num * 2, node, start, mid, x);
//		update(bucket_num * 2 + 1, node, mid + 1, end, x);
//	}
//}

int query(int bucket_num, int start, int end, int left, int right, int x) {

	if (right < start || end < left) return 0;
	if (left <= start && end <= right)
		return bucket[bucket_num].end() - upper_bound(bucket[bucket_num].begin(), bucket[bucket_num].end(), x);

	int mid = (start + end) / 2;
	return query(bucket_num * 2, start, mid, left, right, x) + query(bucket_num * 2 + 1, mid + 1, end, left, right, x);

}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", input + i);
	}

	init(1, 1, n);

	scanf("%d", &m);

	int a, b, c;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", query(1, 1, n, a, b, c));
	}
}