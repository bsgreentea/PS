#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, in[26], map[26][26], chk[26], visited[26], cycle;
string str[101];
vector<int> vt[26];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];

		for (int j = 0; j < str[i].length(); j++) {
			chk[str[i][j] - 'a']++;
		}

		if (i) {
			int len1 = str[i - 1].length();
			int len2 = str[i].length();
			for (int j = 0; j < min(len1, len2); j++) {
				if (str[i - 1][j] != str[i][j]) {
					map[str[i - 1][j] - 'a'][str[i][j] - 'a'] = 1;
					break;
				}
				if (len1 > len2 && j == len2 - 1) cycle = 1;
			}

		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (map[i][j]) {
				vt[i].push_back(j);
				in[j]++;
			}
		}
	}

	queue<int> qu, res;

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (chk[i] && !in[i]) qu.push(i);
		if (chk[i]) cnt++;
	}

	int flag = 0;
	while (qu.size()) {

		if (qu.size() > 1) flag = 1;
		int now = qu.front();
		qu.pop();

		visited[now] = 1;
		res.push(now);

		for (int i = 0; i < vt[now].size(); i++) {
			int next = vt[now][i];
			in[next]--;
			if (in[next] == 0) qu.push(next);
			if (visited[next]) cycle = 1;
		}
	}

	if (cycle || res.size() != cnt) cout << "!\n";
	else if (flag) cout << "?\n";
	else {
		while (res.size()) {
			cout << (char)(res.front() + 'a');
			res.pop();
		}cout << "\n";
	}
}