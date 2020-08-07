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

list<int> adjList[N];

int mx = 0;
int mxnode = -1;
bool vis[N];

void dfs(int root, int dist) {
	vis[root] = 1;
	if (dist > mx) {
		mx = dist;
		mxnode = root;
	}
	for (auto it : adjList[root]) {
		if (vis[it]) continue;
		dfs(it, dist + 1);
	}
	vis[root] = 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	dfs(1, 0);
	int tmp = mxnode;
	dfs(tmp, 0);
	printf("%d\n", mx);
	return 0;
}
		