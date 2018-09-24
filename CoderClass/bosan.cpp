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
LL path[N], dist[N]; 
vector<pair<LL, LL> > adjList[N];

LL dijkstra() {
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > pq;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF64;
		path[i] = 0;
	}
	path[1] = 1;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		LL now = pq.top().second; pq.pop();
		if (dist[now] > dist[n]) break;
		for (auto it = adjList[now].begin(); it != adjList[now].end(); it++) {
			if (dist[it->first] > dist[now] + it->second){
				dist[it->first] = dist[now] + it->second;
				path[it->first] = path[now];
				pq.push({dist[it->first], it->first});
			} else if (dist[it->first] == dist[now] + it->second) {
				path[it->first] = ((path[it->first] % MOD) + (path[now] % MOD)) % MOD;
			}
		}
	}
	return path[n] % MOD;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m ; i++) {
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		adjList[u].pb({v, w});
		adjList[v].pb({u, w});
	}
	printf("%lld\n", dijkstra());
	return 0;
}
		