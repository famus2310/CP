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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

bool bad[2 * N];
bool badEdge[2 * N];
bool vis[2 * N];
bool run;
vector<int> badVert;
map<pair<int, int>, bool> noPath;
vector<pair<LL, LL> > adjList[2 * N];
LL ans = 0LL;

void dfs(LL now, LL lastBad, LL curMin, pair<LL, LL> cand) {
	vis[now] = 1;
	if (now != lastBad && bad[now]) {
		noPath[cand] = 1;
		badEdge[cand.first] = 1;
		ans += curMin;
		return;
	}
	for (auto it : adjList[now]) {
		if (badEdge[now]) return;
		if (noPath[{it.first, now}] || noPath[{now, it.first}]) continue;
		if (!vis[it.first]) {
			if (curMin > it.second) {
				dfs(it.first, lastBad, it.second, {it.first, now});
			}
			dfs(it.first, lastBad, curMin, cand);
		}
	}
}

int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		bad[a] = 1;
		badVert.pb(a);
	}
	LL u, v, w;
	for (int i = 0; i < n - 1; i++) {
		scanf("%lld %lld %lld", &u, &v, &w);
		adjList[u].pb({v, w});
		adjList[v].pb({u, w});
	} 
	for (int it : badVert) {
		SET(vis, 0);
		run = 1;
		dfs(it, it, INF, {0, 0});
	}
	printf("%lld\n", ans);
	return 0;
}
		