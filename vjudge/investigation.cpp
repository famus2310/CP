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

LL dp[15][105][105][2]; //digit_ke, digit_sum, mod k, flag
LL a, b, k;
string cur;

LL solve(LL now, LL sum, LL mod, bool flag) {
	if (now > cur.size()) {
		if (mod == 0 && sum % k == 0) {
			return 1LL;
		}
		else return 0;
	}
	LL &ans = dp[now][sum][mod][flag];
	if (ans != -1)
		return ans;
	ans = 0;
	if (flag) {
		LL curdig = cur[now - 1] - '0';
		ans = ans + solve(now + 1, sum + curdig, (mod * 10 + curdig) % k, 1);
		for (int i = 0; i < curdig; i++) {
			ans = ans + solve(now + 1, sum + i, (mod * 10 + i) % k, 0);
		}
	} else {
		for (int i = 0; i <= 9; i++)
			ans = ans + solve(now + 1, sum + i, (mod * 10 + i) % k, 0);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%lld %lld %lld", &a, &b, &k);
		if (k > 81) {
			printf("Case %d: %lld\n", tc, 0);
			continue;
		}
		cur = to_string(b);
		SET(dp, -1);
		LL hi = solve(1, 0, 0, 1);
		// debug(hi);
		SET(dp, -1);
		cur = to_string(a - 1);
		LL lo = solve(1, 0, 0, 1);
		printf("Case %d: %lld\n", tc, hi - lo);
	}
	return 0;
}
		