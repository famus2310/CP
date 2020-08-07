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

LL days[1005];
LL prefix[1005];

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL n;
		LL year = 0;
		scanf("%lld", &n);
		prefix[0] = 0;
		for (LL i = 1; i <= n; i++) {
			scanf("%lld", days + i);
			year += days[i];
			prefix[i] = prefix[i - 1] + days[i];
		}
		LL yb, mb, db;
		scanf("%lld %lld %lld", &yb, &mb, &db);
		LL yc, mc, dc;
		scanf("%lld %lld %lld", &yc, &mc, &dc);
		LL birth = year * (yb - 1) + (yb - 1) / 4 + prefix[mb - 1] + db;
		LL cur = year * (yc - 1) + (yc - 1) / 4 + prefix[mc - 1] + dc;
		printf("%lld\n", cur - birth + 1);
	}
	return 0;
}
		