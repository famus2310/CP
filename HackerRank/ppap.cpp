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

unordered_map<string, LL> dp;

int main() {
	LL n;
	scanf("%lld", &n);
	LL ans = 0LL;
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'P') {
			ans = (ans % MOD + dp["PPA"] % MOD) % MOD;
			dp["PP"] = (dp["P"] % MOD + dp["PP"] % MOD) % MOD;
			dp["P"] = (dp["P"] % MOD + 1) % MOD;
		} else {
			dp["PPA"] = (dp["PP"] % MOD + dp["PPA"] % MOD) % MOD;
		}
		// cout << dp["P"] << " " << dp["PP"] << " " << dp["PPA"] << " " << dp["PPAP"] << endl;
		// cout << ans << endl;
	}
	printf("%lld\n", ans % MOD);
	return 0;
}
		