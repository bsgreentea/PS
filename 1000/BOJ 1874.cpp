#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int n, arr[100100];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	int now = 0;
	stack<int> st;
	queue<char> qu;

	for (int i = 1; i <= n; i++) {
		if (arr[now] == i) {
			st.push(i);
			qu.push('+');
			qu.push('-');
			st.pop();
			now++;
			while (1) {
				if (st.size() && st.top() == arr[now]) {
					now++;
					qu.push('-');
					st.pop();
				}
				if (st.empty() || st.top() != arr[now]) break;
			}
		}
		else {
			qu.push('+');
			st.push(i);
		}
	}
	for (int i = now; i < n; i++) {
		if (st.size() && arr[now] == st.top()) {
			now++;
			st.pop();
			qu.push('-');
		}
	}
	if (st.empty()) {
		while (qu.size()) {
			printf("%c\n", qu.front());
			qu.pop();
		}
	}
	else {
		puts("NO");
	}
}