#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2, str3;
int lcs[111][111][111];

int main() {

	cin >> str1 >> str2 >> str3;

	str1 = '0' + str1;
	str2 = '0' + str2;
	str3 = '0' + str3;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			for (int k = 0; k < str3.length(); k++) {
				
				if (i == 0 || j == 0 || k == 0) continue;

				if (str1[i] == str2[j] && str1[i] == str3[k])
					lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
				else
					lcs[i][j][k] = max(lcs[i - 1][j][k], max(lcs[i][j - 1][k], lcs[i][j][k - 1]));

			}
		}
	}

	cout << lcs[str1.length() - 1][str2.length() - 1][str3.length() - 1] << "\n";
}