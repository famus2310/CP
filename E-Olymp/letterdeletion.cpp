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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string a, b;
LL dp[205][205];


int main() {
	fastio;
	while (cin >> a >> b) {
		LL sza = a.size();
		LL szb = b.size();
		for (int i = 0; i <= sza; i++) {
			for (int j = 0; j <= szb; j++) {
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else if (a[i - 1] != b[j - 1]) {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				} else dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
		cout << dp[sza][szb] << endl;
	}
	return 0;
}
		