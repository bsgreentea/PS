#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll a, b;
string str1, str2;

int main() {

	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++) {
		a += str1[i] - '0';
	}
	for (int i = 0; i < str2.length(); i++) {
		b += str2[i] - '0';
	}

	cout << a * b << "\n";
}