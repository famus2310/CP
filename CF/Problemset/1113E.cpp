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

int dp[5005][5005];
int arr[5005];
map<int, int> last;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i);
	sort(arr + 1, arr + n + 1);
	SET(dp, 0);
	int mx = 0;
	for (int i = 1; i <= k; i++) {
		deque<int> dq;
		int dp2[5005];
		dp2[0] = 0;
 		for (int j = 1; j <= n; j++) {
			while (!dq.empty() && arr[j] - arr[dq.front()] > 5)
				dq.pop_front();
			int cur;
			if (dq.empty())
				cur = 0;
			else {
				cur = dq.front();
			}
			if (cur == 0)
				dp[j][i] = dp2[j - 1] + 1;
			else dp[j][i] = dp2[cur - 1] + (j - cur + 1);
			// cout << dp[j][i] << " ";
			if (dq.empty() || dq.back() != j)
				dq.push_back(j);
			mx = max(mx, dp[j][i]);
			dp2[j] = max(dp2[j - 1], dp[j][i - 1]);
		}
		// cout << endl;
	}
	printf("%d\n", mx);
	return 0;
}
		