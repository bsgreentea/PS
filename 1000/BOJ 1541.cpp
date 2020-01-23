#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MINUS -1

string str;
vector<string> from, to;

int s2i(string str) {
	int ret = 0;
	for (int i = 0; i < str.length(); i++) {
		ret *= 10;
		ret += str[i] - '0';
	}
	return ret;
}

int main() {

	cin >> str;

	vector<int> trans, zipped;

	int idx = 0;

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		
		if (c == '+') {
			string temp = str.substr(idx, i - idx);
			idx = i + 1;

			trans.push_back(s2i(temp));
		}
		else if (c == '-') {
			string temp = str.substr(idx, i - idx);
			idx = i + 1;

			trans.push_back(s2i(temp));
			trans.push_back(MINUS);
		}
	}
	
	if (idx == 0) {
		printf("%d\n", s2i(str));
		return 0;
	}
	else {
		trans.push_back(s2i(str.substr(idx, str.length() - idx)));
	}

	int temp = 0;
	for (int i = 0; i < trans.size(); i++) {

		if (trans[i] == MINUS) {
			zipped.push_back(temp);
			temp = 0;
		}
		else {
			temp += trans[i];
		}

		if (i == trans.size() - 1) {
			zipped.push_back(temp);
		}
	}
	
	int res = zipped[0];
	for (int i = 1; i < zipped.size(); i++) {
		res -= zipped[i];
	}

	printf("%d\n", res);
}