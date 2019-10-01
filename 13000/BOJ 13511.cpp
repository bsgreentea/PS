#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAX = 1e5;

ll n, m, u, v, k, w, dep[MAX + 1], parent[MAX + 1][18], dist[MAX + 1];
vector<vector<pll>> tree;

void make_tree(ll curr, ll par) {

	for (auto next : tree[curr]) {
		if (next.first == par) continue;
		
		dep[next.first] = dep[curr] + 1;
		dist[next.first] = dist[curr] + next.second;

		parent[next.first][0] = curr;
		make_tree(next.first, curr);
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
		scanf("%lld %lld %lld", &u, &v, &w);
		tree[u].push_back({ v,w });
		tree[v].push_back({ u,w });
	}

	make_tree(1, 0);

	for (ll i = 1; i < 18; i++) {
		for (ll j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	scanf("%lld", &m);

	ll a;
	for (ll i = 0; i < m; i++) {
		
		scanf("%lld", &a);
		
		if (a == 1) {
			scanf("%lld %lld", &u, &v);
			printf("%lld\n", dist[u] + dist[v] - 2 * dist[lca(u, v)]);
		}
		else {
			scanf("%lld %lld %lld", &u, &v, &k);
			
			ll anc = lca(u, v);

			ll target, start;
			if (dep[u] - dep[anc] + 1 >= k) {
				target = k - 1;
				start = u;
			}
			else {
				target = dep[u] + dep[v] - 2 * dep[anc] + 1 - k;
				start = v;
			}

			if (target == 0) {
				printf("%lld\n", start);
				continue;
			}

			while (target) {
				for (ll i = 0; i < 18; i++) {
					if (target < (1 << i)) {
						target -= (1 << (i - 1));
						start = parent[start][i - 1];
						break;
					}
				}
			}
			
			printf("%lld\n", start);
		}
	}
}