#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;

const ll MAX = pow(2, 31);

ll n, k, prime[100100];
priority_queue<ll> pq;

void func(ll num, ll idx) {

	if (num >= MAX) return;
	if (pq.size() < n) pq.push(num);
	else {
		if (num >= pq.top()) {
			return;
		}
		else {
			pq.pop();
			pq.push(num);
		}
	}

	for (ll i = idx; i < k; i++) {
		func(num*prime[i], i);
	}
}

int main() {

	scanf("%lld %lld", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%lld", prime + i);
	}

	for (ll i = 0; i < k; i++) {
		func(prime[i], i);
	}

	printf("%lld\n", pq.top());
}