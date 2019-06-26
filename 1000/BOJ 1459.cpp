#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x, y, w, s;

int main() {

	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);

	ll n = min(x, y);
	if (x < y) swap(x, y);
	ll r = (x + y) % 2;
	printf("%lld\n", min((x + y)*w, min((x - r)*s + r * w, n*s + (x + y - 2 * n)*w)));
}