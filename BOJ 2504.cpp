#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> st;

int main() {

	int temp = 1, res = 0;

	cin >> str;
	char c;
	for (int i = 0; i < str.length(); i++) {
		
		c = str[i];
		if (c == '(') {
			temp *= 2;
			st.push(c);
		}
		else if (c == '[') {
			temp *= 3;
			st.push(c);
		}
		else if (c == ')') {
			if (st.empty() || st.top() != '(') {
				st.push('*');
				break;
			}
			if (str[i - 1] == '(') {
				res += temp;
			}
			st.pop();
			temp /= 2;
		}
		else if (c == ']') {
			if (st.empty() || st.top() != '[') {
				st.push('=');
				break;
			}
			if (str[i - 1] == '[') {
				res += temp;
			}
			st.pop();
			temp /= 3;
		}
	}

	if (st.size()) cout << "0\n";
	else cout << res << "\n";
}