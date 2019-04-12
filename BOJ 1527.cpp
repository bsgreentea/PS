#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

ll a, b, cnt;

void func(ll num) {

	if (num > b || num >= 1000000000) return;
	if (num >= a) cnt++;

	func(num * 10 + 4);
	func(num * 10 + 7);
	return;
}

int main() {

	scanf("%lld %lld", &a, &b);

	func(0);

	printf("%lld\n", cnt);
}