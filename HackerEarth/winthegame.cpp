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

const int NMAX = 1e3 + 5;
LL dp[NMAX][NMAX][2];

LL init(int a, int b, int c) {
	if (a == 0) return dp[a][b][c] = 1;
	if (dp[a][b][c] != -1) return dp[a][b][c];
	dp[a][b][c] = init(a - 2, b, (c + 1) % 2) + (c == 1) ? 1 : 0; 
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		memset(dp, -1, sizeof(dp));
		init(a, b, 1);
		cout << dp[a][b][1] << endl;
	}
	return 0;
}
		