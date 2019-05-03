#include <cstdio>
#include <algorithm>
using namespace std;

int m, t, u, f, d, going[100100], backing[100100];

int main() {

	scanf("%d %d %d %d %d", &m, &t, &u, &f, &d);

	char c;
	for (int i = 0; i < t; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'u') {
			going[i] = u;
			backing[i] = d;
		}
		else if (c == 'f') {
			going[i] = f;
			backing[i] = f;
		}
		else {
			going[i] = d;
			backing[i] = u;
		}
	}

	int tot = 0, res = 0;
	for (int i = 0; i < t; i++) {
		tot += going[i] + backing[i];
		if (tot <= m) res = i + 1;
		else break;
	}

	printf("%d\n", res);
}