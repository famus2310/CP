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

bool isValid[705][705];
int arr[705];
bool dp[705][705][2]; //l, r, isRootRight

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", arr + i);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			isValid[i][j] = isValid[j][i] = (__gcd(arr[i], arr[j]) > 1);
 		} 
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i][0] = dp[i][i][1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int lo = 1; lo + i <= n; lo++) {
			int hi = lo + i;
			dp[lo][hi][0] = 0;
			for (int j = lo + 1; j <= hi; j++) {
				dp[lo][hi][0] |= (dp[lo + 1][j][1] && dp[j][hi][0] && isValid[lo][j] && arr[lo] < arr[j]);
			}
			dp[lo][hi][1] = 0;
			for (int j = lo; j <= hi - 1; j++) {
				dp[lo][hi][1] |= (dp[lo][j][1] && dp[j][hi - 1][0] && isValid[hi][j] && arr[hi] > arr[j]);
			}
		}
	}

	bool ans = 0;
	for (int i = i; i < n; i++) {
		ans |= dp[1][i][1] && dp[i][n][0];
	}
	if (ans)
		puts("Yes");
	else puts("No");
	return 0;
}
		