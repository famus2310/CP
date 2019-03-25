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

LL cube[35];
LL power[35];

int main() {
	for (int i = 0; i < 35; i++) {
		if (i == 0)
			power[i] = 1LL;
		else power[i] = power[i - 1] * 2;
		cube[i] = i * i * i;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		LL n;
			scanf("%lld", &n);
		n /= 2;
		LL ans = 0LL;
		for (LL i = 2; i < 30; i++) {
			if (n < power[i - 2])
				break;
			LL cur = ((n / power[i - 2]) - 1) / 2 + 1;
			// debug(cur);
			ans = ans + cur * cube[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		