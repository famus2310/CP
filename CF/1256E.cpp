#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

ll dp[2 * N][5];
ll arr[2 * N];
ll prefix[2 * N];

int main() {
	NeedForSpeed;
	ll n;
	cin >> n;
	dp[0][0] = 1;
	prefix[0]

	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	SET(dp, -1);
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][3]; 
		dp[i][2] = dp[i - 1][1] + (arr[i] - arr[i - 1]);
		if (dp[i - 2][2] != -1)
			dp[i][3] = dp[i - 1][2] + (arr[i] - arr[i - 2]);
	}
	return 0;
}
		