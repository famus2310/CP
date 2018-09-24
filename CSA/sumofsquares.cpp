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

LL n, k;
LL ans = 0;

void dfs(LL now, LL last, LL cnt, LL sum) {
	debug(last);
	if (now > n || cnt > k) return;
	if (now == n && cnt == k) {
		ans += sum % MOD;
		return;
	}
	if (cnt == k) return;
	for (int i = last; i <= 100; i++) {
		if (now + i > n) break;
		dfs(now + i, i, cnt + 1, (sum + i * i) % MOD);
	}
}

int main() {
	scanf("%lld %lld", &n, &k);
	dfs(0, 1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
		