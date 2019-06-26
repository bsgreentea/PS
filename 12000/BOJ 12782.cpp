#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, res;
string str1, str2;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> str1 >> str2;

		int one = 0, zero = 0;
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] == str2[i]) continue;
			if (str1[i] == '1') one++;
			if (str1[i] == '0') zero++;
		}
		if (one == zero) res = one;
		else {
			res = min(one, zero) + max(one - zero, zero - one);
		}
		cout << res << "\n";
	}
}