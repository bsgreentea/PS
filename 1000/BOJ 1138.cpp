#include <cstdio>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
queue<int> qu, temp;
int n, num[11];

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", num + i);
		pq.push({ -num[i], -i });
	}

	while (pq.size()) {

		int now = -pq.top().second;
		int cnt = -pq.top().first;
		pq.pop();

		if (qu.empty()) {
			qu.push(now); continue;
		}
		if (qu.size() == cnt) {
			qu.push(now); continue;
		}

		while (qu.size()) {
			int tmp = qu.front();
			qu.pop();

			if (tmp > now) cnt--;

			if (cnt == -1) {
				temp.push(now);
				temp.push(tmp);
				while (qu.size()) {
					temp.push(qu.front());
					qu.pop();
				}
				cnt = 100;
				break;
			}

			temp.push(tmp);
		}

		while (temp.size()) {
			qu.push(temp.front());
			temp.pop();
		}

		if (cnt == 0) qu.push(now);
	}

	while (qu.size()) {
		printf("%d ", qu.front());
		qu.pop();
	}puts("");
}