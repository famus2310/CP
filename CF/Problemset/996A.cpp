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
	LL n;
	scanf("%lld", &n);
	LL ans = 0LL;
	if (n >= 100) {
		ans += n / 100;
		n -= 100 * (n / 100);
	}
	if (n >= 20) {
		ans += n / 20;
		n -= 20 * (n / 20);
	}
	if (n >= 10) {
		ans += n / 10;
		n -= 10 * (n / 10);
	}
	if (n >= 5) {
		ans += n / 5;
		n -= 5 * (n / 5);
	}
	if (n > 0) {
		ans += n;
	}
	printf("%lld\n", ans);
	return 0;
}
		