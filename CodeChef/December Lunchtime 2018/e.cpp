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

pair<int, int> adjList[1005];
bool vis[1005];

void dijkstra(LL root) {
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> v;
	pq.push(root);
	dist[root] = 0;
	SET(vis, 0);
	bool neg = 0;
	while (!neg && !pq.empty()) {
		LL now = pq.top();
		pq.pop();
		for (auto it : adjList[now]) {
			if (vis[it,first] && dist[now] + it.second < dist[it.first]) {
				neg = 1;
				break;
			} else if (vis[it.first] && dist[now] + it.second >= dist[it.first])
				continue;
			else if (!vis[it.first]) {
				vis[it.first] = 1;
				pq.push({it.first});
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adjList[a].pb({b, c});
			adjList[b].pb({a, c});
		}
	}
	return 0;
}
		