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

int H[N];
int dp[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", H + i);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = INF;
		for (int j = 1; j <= k && i - j > 0; j++) {
			dp[i] = min(dp[i - j] + abs(H[i] - H[i - j]), dp[i]);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
		