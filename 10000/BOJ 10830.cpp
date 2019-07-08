#include <cstdio>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

const int MOD = 1000;

matrix operator * (matrix& a, matrix& b) {
	
	int sz = a.size();
	matrix ret(sz, vector<int>(sz));

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

int n;
long long b;
matrix m;

matrix func(matrix& a, long long num) {

	if (num == 1) return a;
	else if (num % 2 == 0) {
		matrix t = func(a, num / 2);
		return t * t;
	}
	else {
		matrix t = func(a, num - 1);
		return t * a;
	}
}

int main() {

	scanf("%d %lld", &n, &b);
	m.resize(n);

	int p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &p);
			p %= MOD;
			m[i].push_back(p);
		}
	}

	matrix res = func(m, b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", res[i][j]);
		}puts("");
	}
}