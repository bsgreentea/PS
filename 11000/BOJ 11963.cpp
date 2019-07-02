//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int n, chk[101010];
//vector<int> b;
//priority_queue<int> e1, e2, b1, b2;
//
//int main() {
//
//	scanf("%d", &n);
//	int a;
//	for (int i = 0; i < n / 2; i++) {
//		scanf("%d", &a);
//		chk[a] = 1;
//		e1.push(-a);
//	}
//	for (int i = n / 2; i < n; i++) {
//		scanf("%d", &a);
//		chk[a] = 1;
//		e2.push(a);
//	}
//
//	for (int i = 1; i <= 2 * n; i++) {
//		if (chk[i] == 0) b.push_back(i);
//	}
//	
//	sort(b.begin(), b.end());
//
//	int res = 0;
//	for (int i = n / 2; i < n; i++) {
//		b1.push(-b[i]);
//	}
//
//	int temp = n;
//	while (b1.size() && e1.size()) {
//
//		int ee = -e1.top();
//		int bb = -b1.top();
//
//		if (ee < bb) {
//			e1.pop(); b1.pop(); res++;
//		}
//		else {
//			b1.pop();
//		}
//		temp--;
//		if (temp == 0) break;
//	}
//
//	for (int i = 0; i < n / 2; i++) {
//		b2.push(b[i]);
//	}
//
//	temp = n;
//	while (e2.size() && b2.size()) {
//
//		int ee = e2.top();
//		int bb = b2.top();
//
//		if (ee > bb) {
//			e2.pop(); b2.pop(); res++;
//		}
//		else {
//			b2.pop();
//		}
//		temp--;
//		if (temp == 0) break;
//	}
//
//	printf("%d\n", res);
//}
