#include <iostream>
#include <string>
using namespace std;

const int chker = (1 << 26) - 1;

int n, chk[26], res;
string str;

void func(int now, int idx) {

	if (now == chker) res++;

	for (int i = idx + 1; i < n; i++) {
		func(now | chk[i], i);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			int c = str[j] - 'a';
			chk[i] |= 1 << c;
		}
	}

	func(0, -1);

	printf("%d\n", res);
}