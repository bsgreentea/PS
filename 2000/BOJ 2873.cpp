#include <iostream>
using namespace std;

int r, c, rail[1010][1010];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	int x = 1, y = 1, minn = 10000;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> rail[i][j];
			if (i == r && j == c) continue;
			if (i + j == 2) continue;
			if ((i + j) % 2 == 0) continue;
			if (rail[i][j] < minn) {
				minn = rail[i][j];
				x = i; y = j;
			}
		}
	}

	//for (int i = 1; i <= r; i++) {
	//	for (int j = 1; j <= c; j++) {
	//		cout << rail[i][j];
	//	}cout << endl;
	//}

	//cout << minn << endl;

	if (r & 1) {
		for (int i = 1; i <= r; i++) {
			if (i % 2 == 1) {
				for (int j = 1; j < c; j++) cout << 'R';
				if (i != r) cout << 'D';
			}
			else {
				for (int j = 1; j < c; j++) cout << 'L';
				if (i != r) cout << 'D';
			}
		}
	}
	else {
		if (c & 1) {
			for (int j = 1; j <= c; j++) {
				if (j % 2 == 1) {
					for (int i = 1; i < r; i++) cout << 'D';
					if (j != c) cout << 'R';
				}
				else {
					for (int i = 1; i < r; i++) cout << 'U';
					if (j != c) cout << 'R';
				}
			}
		}
		else {

			char pre = 'D';

			//cout <<"x is " <<x << " y is " << y << "\n";
			rail[1][1] = rail[x][y] = 0;
			x = 1, y = 1;

			int flag = 0;

			while (1) {

				if (x == r && y == c) break;

				rail[x][y] = 0;

				if (flag || (y >= c - 1 && x == 1)) {
					flag = 1;
					if (rail[x][y + 1]) {
						y++; cout << 'R';
					}
					else if (rail[x][y - 1]) {
						y--; cout << 'L';
					}
					else if (rail[x + 1][y]) {
						x++; cout << 'D';
						pre = 'D';
					}
					else break;
				}
				else {
					if (rail[x][y - 1]) {
						y--; cout << 'L';
					}
					else if (pre == 'D' && rail[x + 1][y]) {
						x++; cout << 'D';
						pre = 'D';
					}
					else if (rail[x - 1][y]) {
						x--; cout << 'U';
						pre = 'U';
					}
					else if (rail[x + 1][y]) {
						x++; cout << 'D';
						pre = 'D';
					}
					else if (rail[x][y + 1]) {
						y++; cout << 'R';
					}
					else break;
				}
			}
		}
	}
}