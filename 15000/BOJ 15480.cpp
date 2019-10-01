#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MAX = 1e5;

ll n, m, r, u, v, dep[MAX + 1], parent[MAX + 1][18];
vector<vector<ll>> tree;

void make_tree(ll curr, ll par) {

	for (auto next : tree[curr]) {
		if (next == par) continue;
		
		dep[next] = dep[curr] + 1;
		
		parent[next][0] = curr;
		make_tree(next, curr);
	}
}

ll lca(ll u, ll v) {

	if (dep[u] > dep[v]) swap(u, v);

	for (ll i = 17; i >= 0; i--) {
		ll diff = dep[v] - dep[u];
		if (diff >= (1 << i)) {
			v = parent[v][i];
		}
	}
	if (u == v) return u;

	for (ll i = 17; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}

int main() {

	scanf("%lld", &n);

	tree.resize(n + 1);

	for (ll i = 1; i < n; i++) {
		scanf("%lld %lld", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	make_tree(1, 0);

	for (ll i = 1; i < 18; i++) {
		for (ll j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	scanf("%lld", &m);
	for (ll i = 0; i < m; i++) {
		scanf("%lld %lld %lld", &r, &u, &v);
		
		ll temp = lca(u, v);
		ll tmp1 = lca(u, r);
		ll tmp2 = lca(v, r);

		ll res;
		if (tmp1 == tmp2 && tmp2 == temp) {
			res = tmp1;
		}
		else {
			if (tmp1 == tmp2) res = temp;
			if (tmp1 == temp) res = tmp2;
			if (tmp2 == temp) res = tmp1;
		}

		printf("%lld\n", res);
	}
}