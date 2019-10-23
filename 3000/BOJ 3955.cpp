#include <cstdio>

typedef long long ll;
typedef struct {
	ll x, y, gcd;
} info;

const ll MAX = 1e9;

info x_gcd(ll x, ll y) {

	ll a[3] = { 1,0,x };
	ll b[3] = { 0,1,y };
	ll q, t[3];

	while (1) {

		if (b[2] == 0) return { 0,0,0 };
		if (b[2] == 1) return { b[0],b[1],1 };

		q = a[2] / b[2];
		
		for (int i = 0; i < 3; i++) {
			t[i] = a[i] - q * b[i];
			a[i] = b[i];
		}
		for (int i = 0; i < 3; i++) b[i] = t[i];
	}
}

int main() {

	ll t, k, c;
	scanf("%lld", &t);

	while (t--) {
		scanf("%lld %lld", &k, &c);

		if (c == 1) {
			if (k + 1 > MAX) puts("IMPOSSIBLE");
			else printf("%lld\n", k + 1);
			continue;
		}

		info ret = x_gcd(k, c);
		if (ret.gcd == 0) puts("IMPOSSIBLE");
		else {
			ll ans = ret.y;
			while (ans <= 0) ans += k;

			printf("%lld\n", ans);
		}
	}
}