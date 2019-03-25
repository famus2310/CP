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

LL dp[105][105];
char dir[105][105];
LL grid[105][105];


int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%lld", &grid[i][j]);
	SET(dp, 0);
	for (int i = m; i > 0; i--) {
		for (int j = 1; j <= n; j++) {
			if (dp[i + 1][j] > dp[i][j - 1]) {
				dir[i][j] = 'F';
				dp[i][j] = dp[i + 1][j] + grid[i][j];
 			} else {
 				dir[i][j] = 'R';
 				dp[i][j] = dp[i][j - 1] + grid[i][j];
 			}
 		}
	}
	stack<char> ans;
	int nowx = 1;
	int nowy = n;
	while (nowx != m && nowy != 1) {
		ans.push(dir[nowx][nowy]);
		if (ans.top() == 'F')
			nowx++;
		else nowy--;
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
	return 0;
}
		