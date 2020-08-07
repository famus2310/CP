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

LL power[105];
string s;
LL dp[105][105];

int main() {
	power[0] = 1LL;
	for (LL i = 1; i < 105; i++)
		power[i] = (power[i - 1] * 2) % MOD;
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(dp, 0);
		string s;
		cin >> s;
		for (LL i = 0; i < s.size(); i++)
			dp[i][i] = 1LL;
		for (LL len = 2; len <= s.size(); len++) {
			for (LL i = 0; i + len - 1 < s.size(); i++) {
				LL rg = i + len - 1;
				dp[i][rg] = (dp[i][rg - 1] + dp[i + 1][rg]) % MOD;
				if (s[i] == s[rg])
					dp[i][rg] = (dp[i][rg] + 1) % MOD;
				else dp[i][rg] = (dp[i][rg] - dp[i + 1][rg - 1] + MOD) % MOD;
			}
		}
		LL ans = (power[s.size()] - dp[0][s.size() - 1] - 1 + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
		