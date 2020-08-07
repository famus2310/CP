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

const int N = 1e5 + 5;

LL n, m;
LL coin[1005];
LL dp[1005][30005];
bool vis[1005][30005];

inline void scanint(long long &x)
{    register long long c = getchar_unlocked();
     x = 0;
     long long neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
     if(c=='-') {neg=1;c=getchar_unlocked();}
     for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
 }

LL knapsack() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!vis[i][j]) dp[i][j] = INF64;
			vis[i][j] = 1;
			if (j == 0) dp[i][j] = 0LL;
			else if (i == 0) dp[i][j] = INF64;
			else if (j >= coin[i - 1]) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - coin[i - 1]] + 1);
			} else 
				dp[i][j] = dp[i - 1][j];
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	LL ret = INF64;
	ret = min(ret, dp[n][m]);
	return ret;
}

int main() {
	scanint(n); scanint(m);
	for (int i = 0; i < n; i++) {
		LL a;
		scanint(a); coin[i] = a;
	}
	LL ans = knapsack();
	printf("%lld\n", ans >= INF64 ? -1 : ans);
	return 0;
}
		