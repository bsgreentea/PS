#include <iostream>
#include <string>
using namespace std;

string str1, str2;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str1 >> str2;

	int x = -1, y = -1;
	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				x = i, y = j;
				break;
			}
		}
		if (x != -1) break;
	}

	for (int i = 0; i < str2.length(); i++) {
		for (int j = 0; j < str1.length(); j++) {
			if (i == y)	cout << str1[j];
			else if (j == x) cout << str2[i];
			else cout << '.';
		}cout << "\n";
	}
}