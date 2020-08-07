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

LL sum[N], last[N], cnt[N];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(sum, 0, sizeof sum);
		memset(last, 0, sizeof last);
		memset(cnt, 0, sizeof cnt);
		int n;
		LL ans = 0LL;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			sum[a] = (sum[a] + 1LL * (i - last[a] - 1LL) * cnt[a]) % MOD;
			ans = (ans + sum[a]) % MOD; 
			sum[a] = (sum[a] + cnt[a]) % MOD;
			last[a] = i;
			cnt[a]++;
		}
		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}
		