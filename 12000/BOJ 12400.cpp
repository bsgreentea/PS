#include <iostream>
#include <string>
using namespace std;

int n;
string str, str1 = "yhesocvxduiglbkrztnwjpfmaq";

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();
	for (int t = 1; t <= n; t++) {

		getline(cin, str);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') continue;
			str[i] = str1[str[i] - 'a'];
		}

		cout << "Case #" << t << ": " << str << "\n";
	}
}