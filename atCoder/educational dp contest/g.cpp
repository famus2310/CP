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

vector<int> adjList[N];
int dist[N];

int dfs(int now) {
	if (dist[now] != -1)
		return dist[now];
	int tmp = 0;
	for (auto it : adjList[now]) {
		tmp = max(tmp, dfs(it) + 1);
	}
	return dist[now] = max(tmp, dist[now]);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[a].pb(b);
	}
	SET(dist, -1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == -1) {
			dist[i] = dfs(i);
			ans = max(ans, dist[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
		