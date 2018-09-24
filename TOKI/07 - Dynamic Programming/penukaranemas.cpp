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

const int NMAX = 1e5 + 5;

LL dp[1005];

LL topDown(LL n) {
	if (dp[n] != -1) return dp[n];
	return dp[n] = max(n, topDown(n/2) + topDown(n/3) + topDown(n/4));
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	LL n;
	cin >> n;
	cout << topDown(n) << endl;
	return 0;
}
		