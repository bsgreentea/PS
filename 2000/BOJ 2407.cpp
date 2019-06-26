#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string comb[111][111];

string addNum(string a, string b) {
	long long sum = 0;
	string ret;

	while (a.size() || b.size() || sum) {
		if (a.size()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string nCr(int a, int b) {

	if (a == b || b == 0) return "1";
	if (comb[a][b] != "") return comb[a][b];

	return comb[a][b] = addNum(nCr(a - 1, b - 1), nCr(a - 1, b));
}

int main() {

	cin >> n >> m;
	cout << nCr(n, m) << "\n";
}