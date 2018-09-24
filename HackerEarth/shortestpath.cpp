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

vector<pii> adjList[N];

int dist[N];

void dijkstra() {
	SET(dist, -1);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0, 1});
	dist[1] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int distnow = pq.top().first;
		pq.pop();
		for (auto it : adjList[now]) {
			int tempw = it.second;
			int tempnext = it.first;
			if (dist[tempnext] == -1 || dist[tempnext] > distnow + tempw) {
				dist[tempnext] = distnow + tempw;
				pq.push({dist[tempnext], tempnext});
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adjList[u].pb({v, w});
		adjList[v].pb({u, w});
	}
	dijkstra();
	for (int i = 2; i <= n; i++) {
		printf("%d%c", dist[i], i == n ? '\n' : ' ');
	}
	return 0;
}
		
