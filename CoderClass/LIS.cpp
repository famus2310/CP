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

LL arr[5005];
LL dp[5005];
LL cnt[5005];
LL n;

void init() {
	for (int i = 0; i < n; i++) {
		dp[i] = 1;	
		cnt[i] = 1;
	}
}

void solve() {
	init();
	LL mx = 1;
	LL ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				if (dp[i] > mx) {
					mx = dp[i];
				}
				cnt[i] = cnt[j] % MOD;	
			} else if (arr[j] < arr[i] && dp[j] + 1 == dp[i]) cnt[i] = ((cnt[i] % MOD) + (cnt[j] % MOD)) % MOD;
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] == mx) ret = (ret + cnt[i] % MOD) % MOD;
	}
	printf("%lld %lld\n", mx, ret % MOD);
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", arr + i);
	solve();	
	return 0;
}