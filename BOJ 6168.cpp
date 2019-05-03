#include <iostream>
#include <string>
using namespace std;

string str;
char map[3][3];
int cnto, cntx;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> str;
		if (str[0] == 'e') break;

		int k = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				map[i][j] = str[k];
				if (str[k] == 'O') cnto++;
				else if (str[k] == 'X') cntx++;
				k++;
			}
		}
		
		


	}

}