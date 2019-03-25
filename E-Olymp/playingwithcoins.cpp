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

int ans[185][2];
int dp[185][2];
int prefix[185];

int n;

inline void scanint(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

int main() {
	int k;
	scanint(n);
	int mx = 0;
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanint(a);
		prefix[i] = prefix[i - 1] + a;
	}
	scanint(k);
	SET(dp, 0);
	SET(ans, 0);
	int fly = 0;
	for (int j = n; j >= 1; j--) {
		ans[j][0] = prefix[j] - prefix[j - 1] + ans[j + 2][0];
		dp[j][0] = ans[j][0];
	}
	for (int i = 2; i <= k; i++) {
		fly = fly ^ 1;
		for (int j = n; j >= 1; j--) {
			dp[j + 2 * i][fly] = max(ans[j + 2 * i][fly ^ 1], ans[j + 2 * i][fly]);
			dp[j + 2 * i][fly] = min(dp[j + 2 * i - 1][fly ^ 1], dp[j + 2 * i][fly]);
			int cur = prefix[j + i - 1] - prefix[j - 1];
			ans[j][fly] = max(ans[j][fly ^ 1], cur + dp[j + 2 * i][fly]);
		}
	}
	printf("%d\n", ans[1][fly]);
	return 0;
}
	