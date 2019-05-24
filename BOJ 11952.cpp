#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

const ll MAX = 1e5;

ll n, m, k, s, p, q, dist[MAX + 1], danger[MAX + 1], cost[MAX + 1];
vector<vector<ll>> vt;
queue<ll> zombie;

void set_danger() {

	ll cnt = 0;

	while (zombie.size()) {
		int qs = zombie.size();

		while (qs--) {

			ll here = zombie.front();
			zombie.pop();

			for (ll i = 0; i < vt[here].size(); i++) {
				ll next = vt[here][i];

				if (danger[next] || next == 1 || next == n) continue;
				zombie.push(next);
				danger[next] = 1;
			}
		}
		cnt++;
		if (cnt == s) break;
	}
}

ll solve() {

	memset(dist, -1, sizeof(dist));
	priority_queue<pair<ll, ll>> pq;
	
	pq.push({ -cost[1], 1 });

	while (pq.size()) {
		ll here = pq.top().second;
		ll c = -pq.top().first;
		pq.pop();

		if (dist[here] != -1) continue;

		dist[here] = c;

		for (ll next : vt[here]) {
			ll nc = cost[next] + c;
			if (dist[next] != -1 || danger[next] == 2) continue;
			pq.push({ -nc,next });
		}
	}
	return dist[n];
}

int main() {

	scanf("%lld %lld %lld %lld", &n, &m, &k, &s);
	scanf("%lld %lld", &p, &q);

	vt.resize(n + 1);

	ll a, b;
	for (ll i = 0; i < k; i++) {
		scanf("%lld", &a);
		zombie.push(a);
		danger[a] = 2;
	}

	for (ll i = 0; i < m; i++) {
		scanf("%lld %lld", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	set_danger();

	for (ll i = 1; i <= n; i++) {
		cost[i] = danger[i] ? q : p;
	}

	printf("%lld\n", solve() - cost[1] - cost[n]);
}