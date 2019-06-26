#include <iostream>
#include <string>
using namespace std;

string a, b;

int main() {

	getline(cin, a);
	getline(cin, b);

	int cnt = 0;
	for (int i = 0; i < a.length(); i++) {
		for (int k = i, j = 0; j < b.length(); k++, j++) {
			if (k >= a.length() || a[k] != b[j]) {
				break;
			}
			if (j == b.length() - 1) {
				cnt++;
				i += j;
			}
		}
	}

	if (a.length() < b.length()) cout << 0 << "\n";
	else cout << cnt << "\n";
}