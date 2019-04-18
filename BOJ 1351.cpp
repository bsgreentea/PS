#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

ll n, p, q;
map<ll, ll> mp;

ll func(ll i) {

	if (i == 0) return 1;

	if (mp.find(i) != mp.end()) {
		return mp[i];
	}
	else {
		return mp[i] = func(i / p) + func(i / q);
	}
}

int main() {

	scanf("%lld %lld %lld", &n, &p, &q);

	printf("%lld\n", func(n));
}