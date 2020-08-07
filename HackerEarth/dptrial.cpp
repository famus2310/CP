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

const int NMAX = 1e5 + 5;

LL dp[NMAX];

int main() {
	dp[0] = dp[1] = 1;
	for (int i = 2; i < NMAX; i++) {
		dp[i] = (dp[i - 1] * i) % MOD;
	}
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << dp[x] << endl;
	}
	return 0;
}
		