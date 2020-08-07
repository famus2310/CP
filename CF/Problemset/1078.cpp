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

LL n, m, k;

vector<pair<LL, LL> > adjList[3 * N];
LL par[3 * N];
bool vis[3 * N];
map<pair<int, int>, int> mp;
vector<LL> adjList2[3 * N];
vector<LL> ans;

void dfs(int now) {
	vis[now] = 1;
	if (now == 1) return;
	int parent = par[now];
	if (!vis[parent]) {
		adjList2[parent].pb(now);
		dfs(parent);
	} else {
		adjList2[parent].pb(now);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	bool visited[3 * N];
	memset(visited, 0, sizeof visited);
	visited[1] = 0;
	while (k && !q.empty()) {
		int now = q.front(); q.pop();
		for (auto it : adjList2[now]) {
			// debug(int);
			if (!visited[it]) {
				k--;
				q.push(it);
				visited[it] = 1;
				if (mp[{it, now}])
					ans.pb(mp[{it, now}]);
				else ans.pb(mp[{now, it}]);
				if (k == 0) return;
			}
		}
	}
}

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, 1});
	LL dist[N];
	for (int i = 0; i < N; i++)
		dist[i] = INF64;
	while (!pq.empty()) {
		LL now = pq.top().second;
		LL distnow = pq.top().first;
		pq.pop();
		for (auto it : adjList[now]) {
			if (dist[it.first] > distnow + it.second) {
				par[it.first] = now;
				dist[it.first] = distnow + it.second;
				pq.push({dist[it.first], it.first});
			}
		}
	}
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		mp[{u, v}] = i + 1;
		adjList[u].pb({v, w});
		adjList[v].pb({u, w});
	}
	dijkstra();
	for (int i = 2; i <= n; i++) {
		dfs(i);
	}
	bfs();
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
 	return 0;
}
		