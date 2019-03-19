#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;

ll a, b;

int main() {

	scanf("%lld %lld", &a, &b);
	queue<ll> qu;
	qu.push(a);

	ll cnt = 1, flag = 0;

	while (qu.size()) {
		int qs = qu.size();
		while (qs--) {
			ll now = qu.front();
			qu.pop();

			if (now * 2 == b || now * 10 + 1 == b) {
				flag = 1;
				break;
			}

			if (now * 2 <= b) qu.push(now * 2);
			if (now * 10 + 1 <= b) qu.push(now * 10 + 1);
		}
		cnt++;
		if (flag) break;
	}

	if(flag)
		printf("%lld\n", cnt);
	else puts("-1");
}