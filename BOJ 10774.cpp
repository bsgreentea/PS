#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1;

int j, a, cloth[MAX], res;
vector<pair<int, int>> needs;

int main() {

	scanf("%d %d", &j, &a);

	char c;
	int b, d;
	for (int i = 1; i <= j; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'L') d = 3;
		if (c == 'M') d = 2;
		if (c == 'S') d = 1;
		cloth[i] = d;
	}
	for (int i = 0; i < a; i++) {
		getchar();
		scanf("%c %d", &c, &b);
		if (c == 'L') d = 3;
		if (c == 'M') d = 2;
		if (c == 'S') d = 1;
		needs.push_back({ d,b });
	}

	sort(needs.begin(), needs.end());

	int sz, num;
	for (int i = 0; i < needs.size(); i++) {
		
		sz = needs[i].first;
		num = needs[i].second;

		if (cloth[num] >= sz) {
			cloth[num] = 0;
			res++;
		}
	}

	printf("%d\n", res);
}