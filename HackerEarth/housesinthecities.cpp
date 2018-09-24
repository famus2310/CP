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

const int N = 1e5 + 5;

LL t, n, q;
LL arr[N];
LL dp[N];

int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		dp[0] = 0;
		for (LL i = 1; i <= n; i++) {
			scanf("%lld", arr + i);
			dp[i] = arr[i] + dp[i - 1];
		}
		scanf("%lld", &q);
		while (q--) {
			LL l, r;
			scanf("%lld %lld", &l, &r);
			printf("%lld\n", dp[r] - dp[l - 1]);
		}
	}
	return 0;
}
		