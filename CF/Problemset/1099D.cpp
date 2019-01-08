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

bool vis[N];
LL vertInt[N];
vector<LL> adjList[N];

LL ans = 0LL;

void dfs(LL now, LL par) {
	vis[now] = 1;
	if (vertInt[now] == -1) {
		LL mn = INF64;
		for (LL it : adjList[now])
			mn = min(mn, vertInt[it]);
		vertInt[now] = mn == INF64 ? vertInt[par] : mn;
		if (vertInt[now] < vertInt[par]) {
			puts("-1");
			exit(0);
		}
	}
	// cout << now << " " << vertInt[now] << endl;
	ans += vertInt[now] - vertInt[par];
	for (LL it : adjList[now]) {
		dfs(it, now);
	}
}

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 2; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		adjList[a].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", vertInt + i);	
	}
	ans = vertInt[1];
	dfs(1, 1);
	printf("%lld\n", ans);
	return 0;
}
		