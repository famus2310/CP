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

LL n;
LL w[N];
list<LL> adjList[N];
LL mn = INF;
LL sum = 0;
bool vis[N];

LL dfs(LL now, LL node) {
	LL ans = now;
	for (auto it : adjList[node]) {
		if (vis[it]) continue;
		vis[it] = 1;
		LL tmp = dfs(w[it], it);
		mn = min(mn, abs(sum - tmp - tmp));
		ans += tmp;
		vis[it] = 0;
	}
	return ans;
}

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", w + i);
		sum += w[i];
	}
	for (int i = 0; i < n - 1; i++) {
		LL u, v;
		scanf("%lld %lld", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	for (auto it : adjList[1]) {
		vis[it] = 1;
		LL tmp = (dfs(w[it], it));
		mn = min(mn, abs(sum - tmp - tmp));
		vis[it] = 0;
	}
	printf("%lld\n", mn);
	return 0;
}
		