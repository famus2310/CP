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
const int COUNT = 105;
const int NODE = 105;

vector<LL> adjList[NODE];
LL dp[COUNT][NODE];
LL val[NODE][NODE];

void dfs(LL now, LL prev) {
	LL child = 0LL;
	for (auto it : adjList[now]) {
		if (it == prev)
			continue;
		child++;
		dfs(it, now);
	}
	dp[0][now] = 0;
	for (int i = 1; i < COUNT; i++) {
		dp[i][now] = 0;
		if (child == 0)
			continue;
		else if (child == 1) {
			for (auto it : adjList[now]) {
				if (it != prev)
					dp[i][now] = dp[i - 1][it] + val[now][it];
			}
		} else {
			for (int j = 0; j <= i; j++) {
				LL lf = j;
				LL rg = i - j;
				LL leftNode = -1, rightNode = -1;
				for (auto it : adjList[now]) {
					if (it == prev)
						continue;
					if (leftNode == -1)
						leftNode = it;
					else rightNode = it;
				}
				if (lf == 0)
					dp[i][now] = max(dp[i][now], dp[i - 1][rightNode] + val[now][rightNode]);
				else if (rg == 0)
					dp[i][now] = max(dp[i][now], dp[i - 1][leftNode] + val[now][leftNode]);
				else {
					dp[i][now] = max(dp[i][now], dp[lf - 1][leftNode] + dp[rg - 1][rightNode] + val[now][leftNode] + val[now][rightNode]);
				}
 			}
		}
	}
}

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		LL a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		adjList[a].pb(b);
		adjList[b].pb(a);
		val[a][b] = val[b][a] = c;
	}
	dfs(1, -1);
	printf("%lld\n", dp[k][1]);
	return 0;
}
		