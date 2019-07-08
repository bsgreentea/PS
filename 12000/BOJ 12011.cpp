#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const ll max = 1e18 + 10;

ll n, maxd1[50005], mind1[50005], maxd2[50005], mind2[50005];
vector<p> vt;

bool comp(p& a, p& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {

	scanf("%lld", &n);

	ll a, b, t1 = max, t2 = -100;
	for (ll i = 0; i < n; i++) {

		scanf("%lld %lld", &a, &b);
		vt.push_back({ a,b });

		t1 = min(t1, b);
		t2 = max(t2, b);
	}

	sort(vt.begin(), vt.end());

	ll origin = (vt.back().first - vt[0].first) * (t2 - t1);
	ll res = 0;

	for (ll i = 0; i < vt.size(); i++) {
		if (i == 0) {
			maxd1[i] = vt[i].second;
			mind1[i] = vt[i].second;
		}
		else {
			maxd1[i] = max(maxd1[i - 1], vt[i].second);
			mind1[i] = min(mind1[i - 1], vt[i].second);
		}
	}

	for (ll i = vt.size() - 1; i >= 0; i--) {
		if (i == vt.size() - 1) {
			maxd2[i] = vt[i].second;
			mind2[i] = vt[i].second;
		}
		else {
			maxd2[i] = max(maxd2[i + 1], vt[i].second);
			mind2[i] = min(mind2[i + 1], vt[i].second);
		}
	}

	ll temp1, temp2;
	for (ll i = 0; i < n - 1; i++) {
		temp1 = maxd1[i] - mind1[i];
		temp2 = maxd2[i + 1] - mind2[i + 1];
		res = max(res, origin - temp1 * (vt[i].first - vt[0].first) - temp2 * (vt.back().first - vt[i + 1].first));
	}

	sort(vt.begin(), vt.end(), comp);

	for (ll i = 0; i < vt.size(); i++) {
		if (i == 0) {
			maxd1[i] = vt[i].first;
			mind1[i] = vt[i].first;
		}
		else {
			maxd1[i] = max(maxd1[i - 1], vt[i].first);
			mind1[i] = min(mind1[i - 1], vt[i].first);
		}
	}

	for (ll i = vt.size() - 1; i >= 0; i--) {
		if (i == vt.size() - 1) {
			maxd2[i] = vt[i].first;
			mind2[i] = vt[i].first;
		}
		else {
			maxd2[i] = max(maxd2[i + 1], vt[i].first);
			mind2[i] = min(mind2[i + 1], vt[i].first);
		}
	}

	for (ll i = 0; i < n - 1; i++) {
		temp1 = maxd1[i] - mind1[i];
		temp2 = maxd2[i + 1] - mind2[i + 1];
		res = max(res, origin - temp1 * (vt[i].second - vt[0].second) - temp2 * (vt.back().second - vt[i + 1].second));
	}

	printf("%lld\n", res);
}