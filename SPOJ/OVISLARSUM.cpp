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

LL getSum(LL a) {
	if (a % 2 == 0) {
		return (((a / 2) % MOD) * ((a + 1) % MOD)) % MOD;
	} else return (((a) % MOD) * (((a + 1) / 2) % MOD)) % MOD;
}

int main() {
	LL l, r, m;
	scanf("%lld %lld %lld", &l, &r, &m);
	LL ans;
	if (m <= l && m <= r) {
		LL tmp1 = (getSum(m - 1) - getSum((l - 1) % m) + MOD) % MOD;
		LL tmp2 = ((((r - l) / m) % MOD) * getSum(m - 1)) % MOD;
		ans = (tmp1 + tmp2) % MOD;
	} else if (m > r) {
		ans = (getSum(r) - getSum(l - 1) + MOD) % MOD;
	} else {
		LL tmp1 = (getSum(m - 1) - getSum(l - 1) + MOD) % MOD;
		LL tmp2 = ((((r - m) / m) % MOD) * getSum(m - 1)) % MOD;
		LL tmp3 = getSum(((r - m) % m)) % MOD;
		ans = (tmp1 + tmp2) % MOD;
		ans = (ans + tmp3) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
		