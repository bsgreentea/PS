//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <utility>
//using namespace std;
//
//int n, par[1010];
//vector<pair<int,int>> input;
//vector<pair<int, pair<int,int>>> vt;
//
//int Find(int curr) {
//	if (curr == par[curr]) return curr;
//	return par[curr] = Find(par[curr]);
//}
//
//bool Merge(int x,int y) {
//
//	x = Find(x); y = Find(y);
//	if (x == y) return false;
//	
//	par[x] = y;
//	return true;
//}
//
//int get_dist(pair<int,int>& a, pair<int,int>& b) {
//	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
//}
//
//int main() {
//
//	for (int i = 1; i < 1010; i++) par[i] = i;
//
//	scanf("%d", &n);
//
//	int a, b;
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &a, &b);
//		input.push_back({ a,b });
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			vt.push_back({ get_dist(input[i], input[j]),{i,j} });
//		}
//	}
//
//	sort(vt.begin(), vt.end());
//
//	int res = 0;
//	for (int i = 0; i < vt.size(); i++) {
//		int from = vt[i].second.first;
//		int to = vt[i].second.second;
//		int cost = vt[i].first;
//
//		if (Merge(from, to)) {
//			res = max(res, cost);
//		}
//	}
//
//	printf("%d\n", res);
//}