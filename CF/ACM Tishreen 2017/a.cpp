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

LL power[17];

int main() {
	power[0] = 1;
	for (int i = 1; i < 17; i++) {
		power[i] = power[i - 1] * 10LL;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, x;
		scanf("%lld %lld", &n, &x);
		LL ten = log10(x) + 1;
		LL nine = power[ten] - 1;
		LL mult = ten;
		LL cur = x - 1;
		while (n >= (power[mult] - 1 - cur) * mult) {
			n -= (power[mult] - 1 - cur) * mult;
			cur = power[mult] - 1; 
			mult++;
			// cout << n << " " << cur << endl;
		}
		LL ans;
		if (n % mult != 0)
			ans = -1;
		else ans = (cur + n / mult) - x + 1;
		printf("%lld\n", ans);
	}
	return 0;
}
		