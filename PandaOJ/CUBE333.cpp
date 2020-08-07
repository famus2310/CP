#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const LL INF = 1e12;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

vector<LL> prefix;

int main() {
	prefix.pb(0);
	LL now = 1;
	while (now * now * now <= INF) {
		prefix.pb(now * now * now);
		now++;
	}
	LL t;
	scanf("%lld", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		LL ans1 = upper_bound(all(prefix), b) - prefix.begin() - 1;
		LL ans2 = lower_bound(all(prefix), a) - prefix.begin() - 1;
		LL ans = ans1 - ans2;
		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}
		