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

int n, w;
LL val[105], wt[105];
LL dp[105][100005]; // N, val;

int main() {
    fastio;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];

    for (int i = 0; i < 100005; i++) {
        dp[0][i] = INF64;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 100005; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - val[i] < 0)
                continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - val[i]] + wt[i]);
        }
    }
    // debug("te");
    for (int i = 100004; i >= 0; i--) {
        if (dp[n][i] <= w) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
        