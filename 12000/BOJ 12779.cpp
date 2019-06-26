#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

ll a, b, c, d;

ll gcd(ll a, ll b) {
	ll temp;
	while (b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {

	scanf("%lld %lld", &a, &b);

	c = (ll)ceil(sqrt(a));
	d = (ll)floor(sqrt(b));

	if (c > d) {
		puts("0"); return 0;
	}
	
	ll temp;
	if (c*c == a)
		temp = gcd(d - c, b - a);
	else temp = gcd(d - c + 1, b - a);
	
	if (c*c == a) {
		if (d - c == 0) puts("0");
		else printf("%lld/%lld\n", (d - c) / temp, (b - a) / temp);
	}
	else printf("%lld/%lld\n", (d - c + 1) / temp, (b - a) / temp);
}