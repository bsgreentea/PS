#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 200000;

ll n, m, c, color[MAX + 1], numchild[MAX + 1], cnt;
vector<ll> arr, tree[MAX + 1], bucket[MAX * 4 + 1];
vector<pair<ll, ll>> sub_tree(MAX + 1);

ll make_tree(ll curr, ll parent) {
	for (ll& next : tree[curr]) {
		if (next == parent) continue;
		numchild[curr] += make_tree(next, curr);
	}
	arr.push_back(color[curr]);
	sub_tree[curr] = { cnt - numchild[curr], cnt };
	cnt++;
	return 1 + numchild[curr];
}

void init(ll bucket_num, ll start, ll end) {
	
	if (start == end) {
		bucket[bucket_num].push_back(arr[start]);
		return;
	}
	ll mid = (start + end) / 2;
	init(bucket_num * 2, start, mid);
	init(bucket_num * 2 + 1, mid + 1, end);

	auto& left = bucket[bucket_num * 2];
	auto& right = bucket[bucket_num * 2 + 1];

	merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(bucket[bucket_num]));
}

ll query(ll bucket_num, ll start, ll end, ll left, ll right, ll x) {

	if (right < start || end < left) return 0;
	if (left <= start && end <= right)
		//return distance(bucket[bucket_num].begin(), upper_bound(bucket[bucket_num].begin(), bucket[bucket_num].end(), x));
		return upper_bound(bucket[bucket_num].begin(), bucket[bucket_num].end(), x) - bucket[bucket_num].begin();

	ll mid = (start + end) / 2;
	return (query(bucket_num * 2, start, mid, left, right, x) % MOD +
		query(bucket_num * 2 + 1, mid + 1, end, left, right, x) % MOD) % MOD;
}

int main() {

	scanf("%lld %lld %lld", &n, &m, &c);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", color + i);
	}

	ll a, b;
	for (ll i = 1; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	make_tree(1, 0);
	init(1, 0, n - 1);

	ll res = 0;
	for (ll i = 0; i < m; i++) {
		scanf("%lld %lld", &a, &b);
		res += query(1, 0, n - 1, sub_tree[a].first, sub_tree[a].second, b);
		res %= MOD;
	}

	printf("%lld\n", res);
}