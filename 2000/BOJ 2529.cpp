#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, big_in[10], small_in[10], res[2][10], chk[2][10];
char c[10];

vector<int> vt[10];

void make_res(queue<int>& qu, int a, int num) {

	while (qu.size()) {

		int idx = qu.front();
		qu.pop();

		res[a][idx] = num--;
		chk[a][idx] = 1;

		if (a == 0) {
			for (int i = 0; i < vt[idx].size(); i++) {
				int next = vt[idx][i];
				big_in[next]--;
			}
			for (int i = 0; i <= n; i++) {
				if (big_in[i] == 0 && chk[a][i] == 0) {
					qu.push(i); break;
				}
			}
		}
		else {
			for (int i = vt[idx].size() - 1; i >= 0; i--) {
				int next = vt[idx][i];
				small_in[next]--;
			}
			for (int i = n; i >= 0; i--) {
				if (small_in[i] == 0 && chk[a][i] == 0) {
					qu.push(i); break;
				}
			}
		}
	}
}

int main() {

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf(" %c", c + i);
	}

	for (int i = 1; i <= n; i++) {
		if (c[i] == '<') {
			vt[i].push_back(i - 1);
			big_in[i - 1]++;
			small_in[i - 1]++;
		}
		else {
			vt[i - 1].push_back(i);
			big_in[i]++;
			small_in[i]++;
		}
	}

	queue<int> qu1, qu2;

	for (int i = 0; i <= n; i++) {
		if (big_in[i] == 0) {
			qu1.push(i); break;
		}
	}
	for (int i = n; i >= 0; i--) {
		if (small_in[i] == 0) {
			qu2.push(i); break;
		}
	}

	make_res(qu1, 0, 9);
	make_res(qu2, 1, n);

	for (int i = 0; i <= n; i++) {
		printf("%d", res[0][i]);
	}puts("");
	for (int i = 0; i <= n; i++) {
		printf("%d", res[1][i]);
	}puts("");
}