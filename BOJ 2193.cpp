#include <cstdio>

long long n, pinary[99][2];

int main() {
	
	scanf("%lld", &n);

	pinary[1][1] = 1;
	pinary[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		pinary[i][1] = pinary[i - 1][0];
		pinary[i][0] = pinary[i - 1][0] + pinary[i - 1][1];
	}

	printf("%lld\n", (long long)(pinary[n][1] + pinary[n][0]));
}