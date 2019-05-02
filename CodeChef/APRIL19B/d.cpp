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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL sum[N];
vector<int> adjList[N];
LL cost[N];
LL ans;
LL n, x;

LL dfs(LL now, LL par) {
	LL ret = cost[now];
	for (auto it : adjList[now]) {
		if (it == par)
			continue;
		ret = ret + dfs(it, now);
	}
	return sum[now] = ret;
}

LL solve(int now, int par) {
	LL child = 0LL;
	for (auto it : adjList[now]) {
		if (it == par)
			continue;
		child = child + solve(it, now);
	}
	LL erasenow = -x;
	LL erasechild = cost[now] + child;
	return max(erasenow, erasechild);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < N; i++)
			adjList[i].clear();
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		dfs(1, -1);
		// for (int i = 1; i <= n; i++)
		// 	cout << i << " : " << sum[i] << endl;
		ans = solve(1, -1);
		cout << ans << endl;
	}
	return 0;
}
		