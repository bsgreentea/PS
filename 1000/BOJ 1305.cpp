#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string str;
vector<int> pi;

void getpi() {

	pi.resize(n + 1);

	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}
		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}
}

int main() {

	cin >> n >> str;

	getpi();

	cout << n - pi[n - 1] << "\n";
}