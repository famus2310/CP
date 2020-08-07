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
int memo[N];
bool vis[N];

int dfs(int now) {
	int ret = 1;
	vis[now] = 1;
	for (auto it : adjList[now]) {
		if (!vis[it])
			ret += dfs(it);
	}
	return ret;
}
 
int main() {
	memset(memo, -1, sizeof memo);
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[a].pb(b);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			vis[j] = 0;
		ans = max(ans, dfs(i));
	}
	printf("%d\n", ans);
	return 0;
} 