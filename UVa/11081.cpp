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
const int MOD = 1e4 + 7;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


LL dp[65][65][65];
string s1, s2, s3;

LL solve(LL a, LL b, LL c) {
	if (c == 0) {
		return dp[a][b][c] = 1;
	}
	LL &ret = dp[a][b][c];
	if (ret != -1)
		return ret;
	ret = 0;
	if (a != 0) {
		if (s1[a - 1] == s3[c - 1])
			ret = (ret + solve(a - 1, b, c - 1)) % MOD;
		ret = (ret + solve(a - 1, b, c)) % MOD;
	}
	if (b != 0) {
		if (s2[b - 1] == s3[c - 1]) 
			ret = (ret + solve(a, b - 1, c - 1)) % MOD;
		ret = (ret + solve(a, b - 1, c)) % MOD;
	}
	return ret;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		SET(dp, 0);
		cin >> s1 >> s2 >> s3;
		// LL ans = solve(s1.size(), s2.size(), s3.size());
		// cout << ans << endl;

		LL a = s1.size();
		LL b = s2.size();
		LL c = s3.size();
		for (int i = 0; i < 65; i++)
			for (int j = 0; j < 65; j++)
				dp[i][j][0] = 1;

		for (int i = 1; i <= s3.size(); i++) {
			for (int j = 0; j <= s1.size(); j++) {
				for (int k = 0; k <= s2.size(); k++) {
					LL &ret = dp[j][k][i];
					ret = 0;
					for (int idx = 0; idx < j; idx++)
						if (s1[idx] == s3[i - 1]) 
							ret = (ret + dp[idx][k][i - 1]) % MOD;
					for (int idx = 0; idx < k; idx++)
						if (s2[idx] == s3[i - 1])
							ret = (ret + dp[j][idx][i - 1]) % MOD;
					// cout << j << " " << k << " " << i << " : " << ret << endl; 
				}
			}
			// cout << endl;
		}
		cout << dp[a][b][c] % MOD << endl;
	}
	return 0;
}
/*
2
abc abc abc
abbcd bccde abcd
*/