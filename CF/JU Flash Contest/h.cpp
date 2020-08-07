#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e6 + 5;

int n, m;
// vector<int> adjList[N];
// bool vis[N];

int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			cout << 0;
		else cout << 1;
	}
	cout << endl;
	// for (int i = 0; i < m; i++) {
	// 	int a, b;
	// 	cin >> a >> b;
	// 	adjList[a].pb(b);
	// } 
	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i]) {
	// 		vis[i] = 1;
	// 		topoSort(i);
	// 	}
	// }
	// SET(vis, 0);
	// while (!st.empty()) {
	// 	int now = st.top();
	// 	st.pop();
	// 	// debug(now);
	// 	for (auto it : adjList[now]) {
	// 		if (vis[it])
	// 			mp[{now, it}] = 1;
	// 	}
	// 	vis[now] = 1;
	// }
	// for (auto it : edgeList) {
	// 	int a = it.first;
	// 	int b = it.second;
	// 	cout << mp[{a, b}];
	// }
	// cout << endl;
	return 0;
}
		