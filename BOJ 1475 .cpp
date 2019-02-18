#include <cstdio>

int n, num[9];

int main() {

	scanf("%d", &n);
	int temp;
	while (1) {

		temp = n % 10;
		if (temp == 9) temp = 6;
		num[temp]++;
		n /= 10;

		if (n == 0) break;
	}
	num[6]++;
	num[6] /= 2;

	int res = 0;
	for (int i = 0; i < 9; i++) {
		res = res > num[i] ? res : num[i];
	}

	printf("%d\n", res);
}