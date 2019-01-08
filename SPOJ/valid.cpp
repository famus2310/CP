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

int computeLCS(const string s1, const string s2) {
	// cout << s1 << " " << s2 << endl;
	int dp[s1.size() + 5][s2.size() + 5];
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	return dp[s1.size()][s2.size()];
}

int main() {
	int x;
	// cin >> x;
	for (x = 1; x <= 87; x += 2) {
		int ans = 0;
		int lcs = computeLCS(to_string(ans), to_string(x - ans));
		for (int i = 1; i <= x; i++) {
			int tmpLcs = computeLCS(to_string(i), to_string(x - i));
			if (tmpLcs > lcs) {
				ans = i;
				lcs = tmpLcs;
			}
		}
		cout << "compare : ";
		for (int i = 0; i <= 9; i++) {
			int cur = (x - i) / 11;
			int cur2 = (x - (i * (int)pow(10, (int)log10(x)))) / 2;
			cout << cur << " " << cur2 << endl;
		}
		// cout << x * 10 / 11 << " " << x - x * 10 / 11 << endl;
		cout << "real: ";
		cout << x << ": " << ans << " " << x - ans << endl;
	}
	return 0;
}
		