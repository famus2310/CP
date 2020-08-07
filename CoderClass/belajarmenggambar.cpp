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
bool vis[N];
vector<int> adjList[N];

void dfs(int now) {
	vis[now] = 1;
	for (auto it : adjList[now]) {
		if (!vis[it]) dfs(it);
	} 
}

void solve() {
	bool connect = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) connect = 0;
	}
	int odd = 0;
	for (int i = 1; i <= n; i++) {
		if (adjList[i].size() & 1) odd++;
	}
	// cout << connect << " " << odd << endl;
	if (!connect || odd > 2) {
		puts("Tipe C");
		return;
	} else if (odd == 0)
		puts("Tipe A");
	else 
		puts("Tipe B");
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	dfs(1);
	solve();
	return 0;
}
		