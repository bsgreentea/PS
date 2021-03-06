#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int lcs[1010][1010];

int main() {

	cin >> str1 >> str2;

	str1 = '0' + str1;
	str2 = '0' + str2;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (i == 0 || j == 0) continue;

			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[str1.length() - 1][str2.length() - 1] << "\n";
}