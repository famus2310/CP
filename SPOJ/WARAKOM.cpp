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

bool dp[1005][2];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(dp, 0);
		int n, q, m;
		scanf("%d %d %d", &n, &q, &m);
		dp[q][0] = 1;
		int now = 0;
		for (int i = 0; i < n; i++) {
			now = now ^ 1;
			int x;
			scanf("%d", &x);
			for (int j = 0; j <= m; j++) {
				if (j - x >= 0)
					dp[j - x][now] |= dp[j][now ^ 1];
				if (j + x <= m)
					dp[j + x][now] |= dp[j][now ^ 1];
				dp[j][now ^ 1] = 0;
			}
		}
		int mx = -1;
		for (int i = m; i >= 0; i--) {
			if (dp[i][now]) {
				mx = i;
				break;
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}
		