#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
string str[100100];

map<string, int> mp;

int StoI(string& s) {

	int res = s.front() - '0';
	for (int i = 1; i < s.length(); i++) {
		res = res * 10 + s[i] - '0';
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		mp[str[i]] = i;
	}

	string s;
	while (m--) {
		cin >> s;
		if ('1' <= s[0] && s[0] <= '9')
			cout << str[StoI(s)];
		else cout << mp[s];
		cout << "\n";
	}
}