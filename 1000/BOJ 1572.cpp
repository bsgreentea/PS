#include <cstdio>

typedef long long ll;

const ll MAX = 65536;

ll n, k, num[MAX * 4], sum, tree[MAX * 4];

ll update(ll pos, ll cost, ll node, ll start, ll end) {

	if (pos < start || end < pos) return tree[node];
	if (start == end) return tree[node] += cost;

	ll mid = (start + end) / 2;
	return tree[node] = update(pos, cost, node * 2, start, mid) + update(pos, cost, node * 2 + 1, mid + 1, end);
}

ll query(ll target, ll node, ll start, ll end) {

	if (start == end) return start;

	ll mid = (start + end) / 2;

	if (target <= tree[node * 2])
		return query(target, node * 2, start, mid);
	else
		return query(target - tree[node * 2], node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%lld %lld", &n, &k);

	for (ll i = 1; i <= n; i++) {
		scanf("%lld", num + i);
		update(num[i] + 1, 1, 1, 1, MAX + 1);
		if (i >= k) {
			if (i > k)
				update(num[i - k] + 1, -1, 1, 1, MAX + 1);
			sum += query((k + 1) / 2, 1, 1, MAX + 1) - 1;
		}
	}

	printf("%lld\n", sum);
}