#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int KMAX = 1e5 + 5;

LL dp[KMAX];
LL arr[505];
LL n, k;

void init() {
	for (int i = 0; i <= k; i++) {
		dp[i] = INF;
	}
	dp[0] = 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
		}
	}
	cout << dp[k] << endl;
	return 0;
}
		