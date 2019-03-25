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

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	LL lo = k - 1;
	LL hi = n - k;
	if (k == 1) {
		printf("%lld\n", 3 + 3 * hi);
	} else if (k == n) {
		printf("%lld\n", 3 + 3 * lo);
	} else printf("%lld\n", 3 + 4 * min(lo, hi) + 3 * max(lo, hi));
	return 0;
}
		