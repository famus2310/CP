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

LL n, m;
bool vis[N];
vector<LL> adjList[N];

LL dfs(LL now) {
	vis[now] = 1;
	LL ret = 1;
	for (auto it : adjList[now]){
		if (vis[it]) continue;
		ret += dfs(it);
	}
	return ret;
}

int main() {
	scanf("%lld %lld", &n, &m);
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < m; i++) {
		LL u, v;
		scanf("%lld %lld", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	LL ans = 0LL;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		LL tmp = dfs(i);
		ans = max(ans, tmp * tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
		