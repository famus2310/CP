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

LL dp[20][20][2]; //pos, zero, flag, valid
string cur;
LL lo, hi;

LL solve(LL now, LL nonzero, bool flag) {
	if (now > cur.size()) {
		if (nonzero > 3)
			return 0;
		return 1;
	}
	LL &ans = dp[now][nonzero][flag];
	if (ans != -1)
		return ans;
	ans = 0;
	if (flag) {
		LL lim = cur[now - 1] - '0';
		for (int i = 0; i <= lim; i++)
			ans = ans + solve(now + 1, nonzero + (i != 0), (i == lim));
	} else {
		for (int i = 0; i <= 9; i++)
				ans = ans + solve(now + 1, nonzero + (i != 0), 0);
	}
	// cout << now << " " << nonzero << " " << flag << " " << ans << endl;
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &lo, &hi);
		SET(dp, -1);
		cur = to_string(hi);
		LL a = solve(1, 0, 1);
		// debug(a);
		SET(dp, -1);
		cur = to_string(lo - 1);
		LL b = solve(1, 0, 1);
		printf("%lld\n", a - b);
	}
	return 0;
}
		