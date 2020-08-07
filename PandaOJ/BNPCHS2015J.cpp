#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

vector<int> adjList[20005];
int dist[20005];
queue<pair<int, int> > q;

void init() {
	for (int i = 0; i < 20005; i++) {
		adjList[i].clear();
		dist[i] = -1;
	}
	while (!q.empty()) q.pop();
}

void bfs() {
	while (!q.empty()) {
		int distnow = q.front().first;
		int nodenow = q.front().second;
		q.pop();
		for (int it : adjList[nodenow]) {
			if (dist[it] != -1) continue;
			dist[it] = distnow + 1;
			q.push({distnow + 1, it});
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		init();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		printf("Kasus #%d:\n", tc);
		for (int i = 1; i <= n; i++) {
			if (adjList[i].size() == 1) {
				q.push({0, i});
				dist[i] = 0;
			}
		}
		bfs();
		if (n == 1) dist[1] = 0;
		for (int i = 1; i <= n; i++)
			printf("%d%c", dist[i], i == n ? '\n' : ' ');
	}
	return 0;
}
		