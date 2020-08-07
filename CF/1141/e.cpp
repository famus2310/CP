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

LL prefix[2 * N];

int main() {
	LL h, n;
	scanf("%lld %lld", &h, &n);
	int dies = 0;
	LL red = 0LL;
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		red += a;
		if (h + red <= 0 && dies == 0)
			dies = i;
		prefix[i] = prefix[i - 1] + a;
	}
	if (dies) {
		printf("%d\n", dies);
		return 0;
	}
	if (red >= 0) {
		puts("-1");
		return 0;
	} else {
		LL mn = INF64;
		for (int i = 0; i <= n; i++) {
			LL cur = (-prefix[i] - h) / red + ((prefix[i] + h) % (-red) != 0);
			// debug(-prefix[i] - h);
			mn = min(mn, cur * n + i);
		}
		printf("%lld\n", mn);
	}
	return 0;
}
		