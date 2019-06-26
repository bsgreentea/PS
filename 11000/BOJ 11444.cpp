#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD = 1e9 + 7;

matrix operator * (matrix& a, matrix& b) {

	ll sz = a.size();

	matrix ret(sz, vector<ll>(sz));

	for (ll i = 0; i < sz; i++) {
		for (ll j = 0; j < sz; j++) {
			for (ll k = 0; k < sz; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= MOD;
		}
	}

	return ret;
}

ll n;

int main() {

	scanf("%lld", &n);

	if (n <= 1) {
		printf("%lld\n", n);
		return 0;
	}

	matrix ans = { {1,0},{0,1} };
	matrix a = { {1,1},{1,0} };

	while (n > 0) {
		if (n % 2) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	printf("%lld\n", ans[0][1]);
}