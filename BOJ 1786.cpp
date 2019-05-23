#include <iostream>
#include <string>
#include <vector>
using namespace std;

string t, p;
vector<int> res, pi;

void getpi() {

	pi.resize(p.length());
	int j = 0;
	for (int i = 1; i < p.length(); i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
}

void kmp() {

	for (int i = 0, j = 0; i < t.length(); i++) {
		while (j > 0 && t[i] != p[j]) {
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			if (j == p.length() - 1) {
				res.push_back(i - p.length() + 1);
				j = pi[j];
			}
			else j++;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, t);
	getline(cin, p);

	getpi();
	kmp();

	cout << res.size() << "\n";
	for (int idx : res) {
		cout << idx + 1 << ' ';
	}cout << "\n";

}