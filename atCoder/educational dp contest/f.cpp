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

string s1, s2;
string ret;
int dp[3005][3005];

string LCS() {
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			// cout << i << j << endl;
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int nowi = s1.size();
	int nowj = s2.size();
	while (nowi > 0 && nowj > 0) {
		if (s1[nowi - 1] == s2[nowj - 1]) {
			ret.pb(s1[nowi - 1]);
			nowi--;
			nowj--;
		}
		else if (dp[nowi - 1][nowj] > dp[nowi][nowj - 1]) {
			nowi--;
		} else nowj--;
	} 
	reverse(all(ret));
	return ret;
}

int main() {
	cin >> s1 >> s2;
	cout << LCS() << endl;
	return 0;
}
		