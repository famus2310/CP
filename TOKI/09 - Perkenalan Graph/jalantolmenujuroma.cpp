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

const int NMAX = 125005;

LL n, l, t, x, y;
LL upward[NMAX];
LL backward[NMAX];
list<LL> up[NMAX], down[NMAX];

void dijkstra(LL src, LL* dist, list<LL>* adjList) {
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > pq;
	dist[src] = 0;
	pq.push({0, src});
	while (!pq.empty()) {
		LL now = pq.top().second;
		LL distnow = pq.top().first;
		pq.pop();	
		for (auto it : adjList[now]) {
			if (dist[it] > distnow + 1) {
				dist[it] = distnow + 1;
				pq.push({distnow + 1, it});
			}
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		upward[i] = INF;
		backward[i] = INF;
	}
}

int main() {
	cin >> n >> l >> t >> x >> y;
	init();
	for (int i = 0; i < l; i++) {
		LL a, b;
		cin >> a >> b;
		up[a].pb(b);
		up[b].pb(a);
		down[b].pb(a);
		down[a].pb(b);
	}
	dijkstra(x, upward, up);
	dijkstra(y, backward, down);
	LL now = upward[y];
	for (int i = 0; i < t; i++) {
		LL a, b;
		cin >> a >> b;
		if (upward[a] + backward[b] + 1 < now) {
			now = upward[a] + backward[b] + 1;
		}
		if (upward[b] + backward[a] + 1 < now) {
			now = upward[b] + backward[a] + 1;
		}
	}
	cout << now << endl;
	return 0;
}
		