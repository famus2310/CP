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

LL cnt[N];
map<pair<int, int>, bool> vis;
set<pair<int, int> > s;
vector<int> adjList[N];

void bfs(int now) {
	queue<pair<int, int > > q;
	q.push({0, now});
	while (!q.empty()) {
		int step = q.front().first;
		int nd = q.front().second;
		// debug(nd);
		q.pop();
		if (step == 2) {
			if (nd == now) continue;
			s.insert({min(nd, now), max(nd, now)});
			continue;
		}
		for (auto it : adjList[nd]) {
			q.push({step + 1, it});
		}
	}
}

int main() {
	SET(cnt, 0);
	int n, m;
	scanf("%d %d", &n, &m);
	assert(1 <= n && n <= 100000);
	assert(1 <= m && m <= 100000);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		assert(1 <= u && u <= n);
		assert(1 <= v && v <= n);
		assert(u != v);
		if (u > v) swap(u, v);
		if (vis[{u, v}]) continue;
		vis[{u, v}] = 1;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	cout << s.size() << endl;
	return 0;
}
		