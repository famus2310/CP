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

LL arr[N];

int main() {
	LL t;
	scanf("%lld", &t);
	for (int tc = 1; tc <= t; tc++) {
		if (tc != 1)
			puts("");
		LL ans = -INF;
		LL lastzero = 0;
		LL minlo;
		LL minhi;
		LL n;
		LL mx = -INF;
		LL mxid;
		scanf("%lld", &n);
		LL prefix = 0LL;
		for (int i = 1; i <= n; i++) {
			LL a;
			scanf("%lld", &a);
			prefix += a;
			if (prefix < 0) {
				lastzero = i;
				prefix = 0;
			} else if (prefix > ans) {
				minlo = lastzero + 1;
				minhi = i;
				ans = prefix;
			}
			if (a > mx) {
				mx = a;
				mxid = i;
			}
		}
		if (ans == -INF) {
			ans = mx;
			minhi = minlo = mxid;
		}
		printf("Case %d:\n%lld %lld %lld\n", tc, ans, minlo, minhi);
	}
	return 0;
}
		