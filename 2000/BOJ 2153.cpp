#include <iostream>
#include <string>
using namespace std;

string str;

int main() {

	cin >> str;
	
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			num += str[i] - 'a' + 1;
		}
		else {
			num += str[i] - 'A' + 27;
		}
	}

	for (int i = 2; i < num; i++) {
		if (num%i == 0) {
			cout << "It is not a prime word.\n";
			return 0;
		}
	}
	cout << "It is a prime word.\n";
}