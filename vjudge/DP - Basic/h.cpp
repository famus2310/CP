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


string a, b;
LL dp[2005][2005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				if (i == 0)
					dp[i][j] = j;
				else if (j == 0)
					dp[i][j] = i;
				else if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				}
				// cout << dp[i][j] << " ";
			}
			// cout << endl;
		}
		cout << dp[a.size()][b.size()] << endl;
	}
	return 0;
}
		