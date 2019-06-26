#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> st;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	while (n--) {
		getline(cin, str);

		for (int i = 0; i < str.length(); i++) {
			if (i == str.length() - 1) {
				st.push(str[i]);
				while (st.size()) {
					cout << st.top();
					st.pop();
				}
			}
			else if (str[i] == ' ') {
				while (st.size()) {
					cout << st.top();
					st.pop();
				}cout << ' ';
			}
			else st.push(str[i]);
		}
		cout << "\n";
	}
}