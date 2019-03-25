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

const int N = 2e7 + 5;

// inline void scanint(int &x) {
// 	register int c = getchar_unlocked();
// 	x = 0;
// 	int neg = 0;
// 	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
// 	if (c == '-') {
// 		neg = 1; 
// 		c = getchar_unlocked();
// 	}
// 	for (; c > 47 && c < 58; c = getchar_unlocked())
// 		x = (x << 1) + (x << 3) + c - 48;
// 	if (neg) x = -x;
// }

map<int, int> dp;

int solve(int n) {
	if (n == 1)
		return 0;
	if (dp.find(n) != dp.end())
		return dp[n];
	dp[n] = 100000000;
	if (n % 3 == 0)
		return dp[n] = solve(n / 3) + 1;
	else {
		if (n % 2 == 0)
			dp[n] = solve(n / 2) + 1;
		dp[n] = min(dp[n], solve(n - 1) + 1);
	}
	return dp[n];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", tc, solve(n));
	}
	return 0;
}
		