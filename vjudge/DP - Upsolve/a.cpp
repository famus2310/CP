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

LL amount[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
LL dp[30005];

void preprocess() {
	SET(dp, 0);
	dp[0] = 1;
	for (int i = 0; i < 11; i++) {
		for (int j = amount[i]; j < 30005; j++)
			dp[j] += dp[j - amount[i]];
	}
}

int main() {
	preprocess();
	double n;
	while (scanf("%lf", &n) && n) {
		LL x = LL(n * 100);
		cout.precision(2);
		cout << fixed;
		cout << right << setw(6) << n << setw(17) << dp[x] << endl;
	}
	return 0;
}
