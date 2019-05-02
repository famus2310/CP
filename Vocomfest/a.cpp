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

LL npc[N][5]; // day, no NPC
LL dp[N][5];
bool special[N];

int main() {
	fastio;
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		LL n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 4; j++) {
				LL a;
				cin >> a;
				npc[i][j] = a; 
				dp[i][j] = 0LL;
			}
			special[i] = 0;
		}
		special[0] = 0;
		dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 0;
		for (int i = 0; i < m; i++) {
			LL a;
			cin >> a;
			special[a] = 1;
		}
		for (int i = 1; i <= n; i++) {
			LL a = dp[i - 1][1];
			LL b = dp[i - 1][2];
			LL c = dp[i - 1][3];
			LL d = dp[i - 1][4];
			if (special[i - 1]) {
				dp[i][1] = max(max(a + npc[i][1] * 2, b + npc[i][1]), max(c + npc[i][1], d + npc[i][1]));
				dp[i][2] = max(max(a + npc[i][2], b + npc[i][2] * 2), max(c + npc[i][2], d + npc[i][2]));
				dp[i][3] = max(max(a + npc[i][3], b + npc[i][3]), max(c + npc[i][3] * 2, d + npc[i][3]));
				dp[i][4] = max(max(a + npc[i][4], b + npc[i][4]), max(c + npc[i][4], d + npc[i][4] * 2));
			} else {
				dp[i][1] = max(max(a + npc[i][1], b + npc[i][1]), max(c + npc[i][1], d + npc[i][1]));
				dp[i][2] = max(max(a + npc[i][2], b + npc[i][2]), max(c + npc[i][2], d + npc[i][2]));
				dp[i][3] = max(max(a + npc[i][3], b + npc[i][3]), max(c + npc[i][3], d + npc[i][3]));
				dp[i][4] = max(max(a + npc[i][4], b + npc[i][4]), max(c + npc[i][4], d + npc[i][4]));
			}
		}
		LL ans = max(max(dp[n][1], dp[n][2]), max(dp[n][4], dp[n][3]));
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
