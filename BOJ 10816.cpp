#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, card[500500];

int count(int target) {
	return (upper_bound(card, card + n, target) - card)
		- (lower_bound(card, card + n, target) - card);
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", card + i);
	}

	sort(card, card + n);

	scanf("%d", &m);

	int a;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		printf("%d ", count(a));
	}puts("");
}