#include <iostream>
#include <string>
using namespace std;

string str1, str2;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str1 >> str2;

	if (str1.length() < str2.length()) {
		cout << "0\n";
		return 0;
	}

	int cnt = 0, flag = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str2[0]) {
			flag = 0;
			for (int j = 0; j < str2.length(); j++) {
				if (i+j >= str1.length() || str1[i + j] != str2[j]) {
					flag = 1; break;
				}
			}
			if (!flag) cnt++;
		}
	}

	cout << cnt << "\n";
}