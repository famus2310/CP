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

char s[2 * N];
int dp[2 * N][3]; //pos, RGB

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", s + i);
		if (i == 0) {
			dp[i][0] = s[i] != 'R';
			dp[i][1] = s[i] != 'G';
			dp[i][2] = s[i] != 'B';
		} else {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + (int)(s[i] != 'R');
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + (int)(s[i] != 'G');
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + (int)(s[i] != 'B');
		}
		// cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	}
	int minid;
	if (dp[n - 1][0] < dp[n - 1][1] && dp[n - 1][0] < dp[n - 1][2])
		minid = 0;
	else if (dp[n - 1][1] < dp[n - 1][2])
		minid = 1;
	else minid = 2;
	printf("%d\n", dp[n - 1][minid]);
	int now = minid;
	for (int i = n - 1; i > 0; i--) {
		if (now == 0) {
			s[i] = 'R';
			if (dp[i - 1][1] < dp[i - 1][2])
				now = 1;
			else now = 2;
		}
		else if (now == 1) {
			s[i] = 'G';
			if (dp[i - 1][0] < dp[i - 1][2])
				now = 0;
			else now = 2;
		}
		else {
			s[i] = 'B';
			if (dp[i - 1][1] < dp[i - 1][0])
				now = 1;
			else now = 0;
		}
	}
	if (now == 0)
		s[0] = 'R';
	else if (now == 1)
		s[0] = 'G';
	else s[0] = 'B';
	printf("%s\n", s);
	return 0;
}
		