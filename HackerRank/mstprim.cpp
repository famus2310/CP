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
vector<pair<LL, LL> > adjList[N];
bool vis[N];

LL prim() {
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > pq;
	LL ret = 0LL;
	pq.push({0, 1});
	while (!pq.empty()) {
		LL now = pq.top().second;
		LL costnow = pq.top().first; pq.pop();
		if (vis[now]) continue;
		vis[now] = true;
		ret += costnow;
		for (auto it : adjList[now]) {
			if (!vis[it.first]) {
				pq.push({it.second, it.first});
			}
		}
	}
	return ret;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) {
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		adjList[u].pb({v, w});
		adjList[v].pb({u, w});
	}
	LL ans = prim();
	printf("%lld\n", ans);
	return 0;
}
		