#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

int n;
string str;

map<string, int> mp;
map<string, int>::iterator it;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> str;
		if (mp.find(str) == mp.end()) {
			mp[str] = 1;
		}
		else mp[str] = mp[str] + 1;
	}

	string res = mp.begin()->first;
	int maxn = 0;
	for (it = mp.begin(); it != mp.end(); it++) {
		if (it->second > maxn) {
			maxn = it->second;
			res = it->first;
		}
		if (it->second == maxn) {
			if (it->first < res) res = it->first;
		}
	}

	cout << res << "\n";
}