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

int n, m, k;
int shovel[2 * N];
pair<int, int> disc[2 * N];
int dp[2 * N];
int prefix[2 * N];

int main() {
	fastio;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> shovel[i];
	}
	sort(shovel + 1, shovel + n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		disc[i] = {a, b};
	}
	prefix[0] = 0;
	for (int i = 1; i <= n; i++)
		prefix[i] = shovel[i] + prefix[i - 1];
	dp[0] = 0;
 	for (int i = 1; i <= k; i++) {
		dp[i] = prefix[i];
		for (int j = 0; j < m; j++) {
			if (disc[j].first > i)
				continue;
			int now = dp[i - disc[j].first] + prefix[i] - prefix[i + disc[j].second - disc[j].first];
			dp[i] = min(dp[i], now);
		}
		// cout << i << " " << dp[i] << endl;
	}
	cout << dp[k] << endl;
	return 0;
}
		