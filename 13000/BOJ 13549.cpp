#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 100010;

int n, k, visited[2 * MAX + 1];
queue<pair<int, int>> qu;

int main() {

	scanf("%d %d", &n, &k);

	qu.push({ n,0 });
	visited[n]++;

	int flag = 0, res = 0;
	while (qu.size()) {
		int now = qu.front().first;
		int time = qu.front().second;
		qu.pop();

		if (now) {
			for (int i = now; i <= MAX; i *= 2) {
				if (i == k) {
					res = time; flag++; break;
				}
				if (!visited[i]) {
					qu.push({ i,time });
					visited[i]++;
				}
			}
		}
		if (flag) break;

		if (now + 1 == k | now - 1 == k) {
			res = time + 1; break;
		}

		if (now + 1 <= 2*MAX && !visited[now + 1]) {
			qu.push({ now + 1,time + 1 });
			visited[now + 1]++;
		}
		if (now - 1 >= 0 && !visited[now - 1]) {
			qu.push({ now - 1, time + 1 });
			visited[now - 1]++;
		}
	}
	printf("%d\n", res);
}