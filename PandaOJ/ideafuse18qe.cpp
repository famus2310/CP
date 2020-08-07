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

int n, m;
vector<int> adjList[10005];
int ans[10005];

void bfs(int node, int dist) {
	queue<pair<int, int> > q;
	bool vis[10005];
	memset(vis, 0, sizeof vis);
	q.push({node, 0});
	while (!q.empty()) {
		int now = q.front().first;
		int distnow = q.front().second; q.pop();
		// debug(now);
		if (vis[now]) continue;
		vis[now] = 1;
		if (distnow == dist) {
			ans[now]++;
			continue;
		}
		for (auto it : adjList[now]) {
			if (vis[it]) continue;
			q.push({it, distnow + 1});
		}
	}
}

int main() {
	memset(ans, 0, sizeof ans);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		bfs(u, v);
	}
	int mxnow = -1;
	for (int i = 1; i <= n; i++) {
		// debug(ans[i]);	
		mxnow = max(mxnow, ans[i]);
	}
	printf("%d\n", mxnow);
	return 0;
}
		