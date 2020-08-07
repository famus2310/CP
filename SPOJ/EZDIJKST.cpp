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

const int N = 1e4 + 5;

vector<pair<int, int> > adjList[N];

int n, m;

int dijkstra(int src, int dst) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, src});
	vector<int> dist(n + 5, INF);
	dist[src] = 0;
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		// cout << now.first << " " << now.second << endl;
		if (now.second == dst) return now.first;
		for (auto it : adjList[now.second]) {
			if (dist[it.second] > now.first + it.first) {
				dist[it.second] = now.first + it.first;
				pq.push({dist[it.second], it.second});
			}
		}
	}
	return -1;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 10005; i++)
			adjList[i].clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adjList[u].pb({w, v});
		}
		int a, b;
		cin >> a >> b;
		int ans = dijkstra(a, b);
		if (ans == -1) cout << "NO" << endl;
		else cout << ans << endl;
	}
	return 0;
}
		