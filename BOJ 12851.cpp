#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 100001;

int n, k, visited[MAX];
queue<int> qu;

int main() {

	scanf("%d %d", &n, &k);
	
	if (n == k) {
		puts("0\n1");
		return 0;
	}

	qu.push(n);
	
	int way, time, flag;
	way = time = flag = 0;

	while (qu.size()) {
		int qs = qu.size();
		while (qs--) {
			int here = qu.front();
			qu.pop();

			visited[here]++;

			if (here + 1 == k || here - 1 == k || here * 2 == k) {
				flag++; way++;
			}

			if (here + 1 <= k && !visited[here + 1]) {
				qu.push(here + 1);
			}
			if (here - 1 >= 0 && !visited[here - 1]) {
				qu.push(here - 1);
			}
			if (here * 2 <= MAX && !visited[here * 2]) {
				qu.push(here * 2);
			}
		}
		time++;
		if (flag) break;
	}

	printf("%d\n%d\n", time, way);
}