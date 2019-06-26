#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll n, maxn = LLONG_MIN, num1[20], num2[20];
char arr[20];

ll Add(ll a, ll b) {
	return a + b;
}

ll Sub(ll a, ll b) {
	return a - b;
}

ll Mul(ll a, ll b) {
	return a*b;
}

ll calc(char c, ll a, ll b) {
	if (c == '+')
		return Add(a, b);
	else if (c == '-')
		return Sub(a, b);
	else if (c == '*')
		return Mul(a, b);
}

void func(ll temp, ll idx) {

	if (idx == n - 1) {
		maxn = max(maxn, temp);
		return;
	}
	if(idx + 2 <= n-1)
		func(calc(arr[idx + 1], temp, num1[idx + 2]), idx + 2);
	if(idx + 4 <= n-1)
		func(calc(arr[idx + 1], temp, num2[idx + 2]), idx + 4);
}

int main() {

	scanf("%lld", &n);
	getchar();
	for (ll i = 0; i < n; i++) {
		scanf("%c", arr + i);
		if (i % 2 == 0)
			num1[i] = arr[i] - '0';
	}

	for (ll i = 0; i < n - 2; i += 2) {
		num2[i] = calc(arr[i + 1], num1[i], num1[i + 2]);
	}

	if (n == 1) {
		printf("%lld\n", num1[0]);
		return 0;
	}

	func(num1[0], 0);
	func(num2[0], 2);

	printf("%lld\n", maxn);
}