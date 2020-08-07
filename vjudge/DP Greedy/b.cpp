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


int main() {
	int n;
	scanf("%d", &n);
	LL lastx = 0;
	LL lasty = 0;
	LL ans = 1LL;
	for (int i = 1; i <= n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		if (lastx == lasty) {
			ans = ans + min(a - lastx, b - lasty);
		} else if (lastx < lasty) {
			ans = ans + max(0LL, min(b - lasty + 1, a - lasty + 1));
		} else {
			ans = ans + max(0LL, min(a - lastx + 1, b - lastx + 1));
		}
		// debug(ans);
		lastx = a;
		lasty = b;
	}
	printf("%lld\n", ans);
	return 0;
}
		