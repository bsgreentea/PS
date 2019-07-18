#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const ll INF = 1e18;

ll w, h, g, map[33][33], dist[33][33], time[33][33];
p exits[33][33];

ll dx[] = { 0,0,1,-1 };
ll dy[] = { 1,-1,0,0 };

ll chk(ll x, ll y) {
	return x >= 0 && y >= 0 && x < w && y < h && map[x][y] != INF;
}

int main() {

	while (1) {

		scanf("%lld %lld", &w, &h);

		for (ll i = 0; i < w; i++) {
			for (ll j = 0; j < h; j++) {
				dist[i][j] = INF;
				map[i][j] = 0;
				time[i][j] = INF;
			}
		}

		if (w + h == 0) break;

		scanf("%lld", &g);

		ll a, b, c, d, e, t;
		for (ll i = 0; i < g; i++) {
			scanf("%lld %lld", &a, &b);
			map[a][b] = INF;
		}

		scanf("%lld", &e);
		for (ll i = 0; i < e; i++) {
			scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &t);
			time[a][b] = t;
			exits[a][b] = { c,d };
			//if (a == c && b == d) map[a][b] = INF;
		}

		dist[0][0] = 0;

		ll cycle = 0;
		for (ll k = 0; k < w*h; k++) {
			for (ll i = 0; i < w; i++) {
				for (ll j = 0; j < h; j++) {

					if (map[i][j] == INF) continue;
					if (i == w - 1 && j == h - 1) continue;

					if (time[i][j] != INF) {
						ll nx = exits[i][j].first;
						ll ny = exits[i][j].second;
						ll ncost = time[i][j];

						if (dist[i][j] != INF && dist[nx][ny] > dist[i][j] + ncost) {
							dist[nx][ny] = dist[i][j] + ncost;
							if (k == w * h - 1) cycle = 1;
						}
					}

					if (time[i][j] == INF) {
						for (ll ii = 0; ii < 4; ii++) {
							ll nx = i + dx[ii];
							ll ny = j + dy[ii];
							if (!chk(nx, ny)) continue;

							if (dist[i][j] != INF && dist[nx][ny] > dist[i][j] + 1) {
								dist[nx][ny] = dist[i][j] + 1;
								if (k == w * h - 1) cycle = 1;
							}
						}
					}
				}
			}
		}

		if (cycle) puts("Never");
		else if (dist[w - 1][h - 1] == INF) puts("Impossible");
		else printf("%lld\n", dist[w - 1][h - 1]);
	}
}