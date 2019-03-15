#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[26];

int main() {

	freopen("input.txt", "r", stdin);

	char c;
	int maxn = 0;
	while (scanf("%c", &c) != EOF) {
		if (c != '\0' && c != ' ' && c != '\n')
			cnt[c - 'a']++, maxn = max(maxn, cnt[c - 'a']);
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] == maxn)
			printf("%c ", i + 'a');
	}puts("");
}