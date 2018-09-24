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
LL mx = -1;
bool vis[N];
stack<LL> st;

void topoSort(LL now) {
	vis[now] = 1;
	for (auto it = adjList[now].begin(); it != adjList[now].end(); it++) {
		if (!vis[it->first]) topoSort(it->first);
	}
	st.push(now);
}

LL solve() {
	LL dist[N];
	for (LL i = 0; i <= n; i++)
		dist[i] = -INF64;
	dist[1] = 0;
	while (!st.empty()) {
		LL now = st.top(); st.pop();
		if (dist[now] != -INF64) {
			for (auto it = adjList[now].begin(); it != adjList[now].end(); it++) {
				if (dist[it->first] < dist[now] + it->second) {
					dist[it->first] = dist[now] + it->second;
				}
			}
		}
	}
	return dist[n] == -INF64 ? -1 : dist[n];
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (LL i = 0; i < m; i++) {
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		adjList[u].pb({v, w});
	}
	topoSort(1);
	printf("%lld\n", solve());
	return 0;
}
		