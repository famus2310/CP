#include <iostream>
#include <stdio.h>
#include <algorithm>
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

LL dp[N];
LL n, m;
LL val[505];
LL w[505];

LL solve() {
	for (int i = 0; i <= m; i++)
		dp[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
		}
	}
	return dp[m];
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", w + i, val + i);
	}
	printf("%lld\n", solve());
	return 0;
}
		