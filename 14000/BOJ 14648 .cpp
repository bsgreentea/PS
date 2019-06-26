#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, qs;
vector<ll> input, tree;

ll init(ll node, ll start, ll end) {

	if (start == end) return tree[node] = input[start];

	ll mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll update(ll pos, ll val, ll node, ll start, ll end) {

	if (pos < start || end < pos) return tree[node];

	if (start == end) return tree[node] = val;

	ll mid = (start + end) / 2;
	return tree[node] = update(pos, val, node * 2, start, mid) + update(pos, val, node * 2 + 1, mid + 1, end);
}

ll query(ll left, ll right, ll node, ll start, ll end) {

	if (end < left || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	ll mid = (start + end) / 2;
	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%lld %lld", &n, &qs);
	input.resize(n + 1);

	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &input[i]);
	}

	ll h = (ll)ceil(log2(n));
	ll ts = (1 << (h+1));

	tree.resize(ts);

	init(1, 1, n);

	ll q, a, b, c, d;
	while (qs--) {
		scanf("%lld", &q);
		if (q == 1) {
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", query(a, b, 1, 1, n));
			
			update(a, input[b], 1, 1, n);
			update(b, input[a], 1, 1, n);
			swap(input[a], input[b]);
		}
		else {
			scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
			printf("%lld\n", query(a, b, 1, 1, n) - query(c, d, 1, 1, n));
		}
	}
}