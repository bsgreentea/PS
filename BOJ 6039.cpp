#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

double f[22], m[22];
int n;

vector<pair<double, string>> vt;

void func(int cnt, double force, double mass, string str) {

	if (cnt == n) {
		vt.push_back({ force / mass, str});
		return;
	}

	func(cnt + 1, force, mass, str + "0");
	func(cnt + 1, force + f[cnt + 1], mass + m[cnt + 1], str + "1");
}

int main() {

	scanf("%lf %lf %d", &f[0], &m[0], &n);
	double a, b;
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", f + i, m + i);
	}

	func(0, f[0], m[0], "");

	sort(vt.begin(), vt.end());

	string res = vt.back().second;

	int flag = 0;
	for (int i = 0; i < res.length(); i++) {
		if (res[i] == '1') {
			printf("%d\n", i + 1);
			flag++;
		}
	}

	if (!flag) puts("NONE");
}