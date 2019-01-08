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

LL dp[N][2]; //0 = white, 1 black
bool vis[N];
vector<int> adjList[N];
LL ans = 0LL;

void dfs(int now) {
	vis[now] = 1;
	LL cnt = 0LL;
	for (auto it : adjList[now]) {
		if (!vis[it]) {
			cnt++;
			dp[it][0] = (dp[it][0] + (dp[now][1] + dp[now][0])) % MOD;
			dp[it][1] = (dp[it][1] + dp[now][0]) % MOD;
			dfs(it);
		}
	}
	if (cnt == 0) {
		cout << dp[now][1] << " " << dp[now][0] << endl;
		ans = (ans + (dp[now][1] + dp[now][0]) % MOD) % MOD;
	}
}

int main() {
	SET(dp, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dp[1][0] = 1;
	dp[1][1] = 1;
	dfs(1);
	printf("%lld\n", ans % MOD);
	return 0;
}
		