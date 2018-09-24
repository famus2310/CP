#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int prim(bool vis[], vector<int>* adj) {
	queue<int> q;
	q.push(1);
	int ret = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		// debug(now);
		if (vis[now]) continue;
		vis[now] = true;
		ret++;
		for (auto it : adj[now]) {
			if (!vis[it]) {
				q.push(it);
			}
		}
	}
	return ret - 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		vector<int> adjList[a + 1];
		for (int i = 0; i < b; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		// for (int i = 1; i <= a; i++) {
		// 	for (int j = 0; j < adjList[i].size(); j++) {
		// 		cout << adjList[i][j] << " ";
		// 	}
		// 	puts("");
		// }
		bool vis[a + 1];
		memset(vis, 0, sizeof vis);
		int ans = prim(vis, adjList);
		printf("%d\n", ans);
	}
	return 0;
}
		