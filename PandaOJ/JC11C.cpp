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

int arr[505];
LL dp[5005 * 2];

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = 0;
	for (LL i = 1; i <= arr[n - 1] * 2; i++) {
		dp[i] = INF64;
		for (int j = 0; j < n && i - arr[j] >= 0; j++)
			dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		LL greed = 0;
		LL tmp = i;
		for (int j = n - 1; j >= 0; j--) {
			if (tmp >= arr[j]) {
				greed = greed + (tmp / arr[j]);
				tmp -= (tmp / arr[j]) * arr[j];
			}
		}
		// debug(dp)
		if (dp[i] != greed) {
			cout << "NO " << i << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
		