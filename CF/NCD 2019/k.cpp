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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL prefix[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, x;
		scanf("%lld %lld", &n, &x);
		prefix[0] = 0;
		for (int i = 1; i <= n; i++) {
			LL a;
			scanf("%lld", &a);
			prefix[i] = prefix[i - 1] + a;
		}
		LL ans = 0LL;
		for (LL i = 1; i <= n; i++) {
			LL target = prefix[i - 1] + x;
			LL ub = lower_bound(prefix + i, prefix + n + 1, target) - prefix;
			ans = ans + ub - i;
		}
		printf("%lld\n", ans);	
	}
	return 0;
}
		