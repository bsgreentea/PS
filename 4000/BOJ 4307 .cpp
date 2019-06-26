#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int tc, l, n;
vector<int> ant;

int main() {

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &l, &n);
		ant.resize(n);
		
		int mint = 0, maxt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &ant[i]);

			int temp = min(ant[i], l - ant[i]);
			mint = max(mint, temp);

			maxt = max(maxt, l - ant[i]);
			maxt = max(maxt, ant[i]);
		}

		printf("%d %d\n", mint, maxt);
	}

}