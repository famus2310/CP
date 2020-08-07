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

LL dp[20][1024][2]; //now, mask, flag
LL ten[20];
LL a, b, c;
string cur;

LL solve(int now, int mask, bool flag) {
	if (now > cur.size()) {
		int elem = __builtin_popcount(mask);
		if (elem > c)
			return 0;
		else return 1;
	}
	LL &ans = dp[now][mask][flag];
	if (ans != -1)
		return ans;
	if (flag) {
		int lim = cur[now - 1] - '0';
		for (int i = 0; i <= lim; i++)
			ans = ans + solve(now + 1, mask | (1 << i), flag | (i == lim));
	} else {
		for (int i = 0; i <= lim; i++)
			ans = ans + solve(now + 1, mask | (1 << i), 0);
	}
	return ans;
}

LL calc(LL x) {
	cur = to_string(x);
	LL now = solve(1, 0, 1);
	LL ans = 0LL;
	for (int i = 1; i <= cur.size(); i++) {
		for (int j = 0; j < 1024; j++) {
			for (int k = 0; k <= cur[i] - '0'; k++) {
				ans = (ans + ((ten[cur.size() - i + 1] * k) % MOD) * dp[i][j][0]) % MOD;
				
			}
		}
	}
	return ans;
}

int main() {
	ten[0] = 1LL;
	for (LL i = 2; i < 20; i++)
		ten[i] = ten[i - 1] * 10;
	scanf("%lld %lld %lld", &a, &b, &c);

	return 0;
}
		