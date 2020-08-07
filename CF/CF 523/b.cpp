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

LL h[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	LL ans = 0LL;
	LL last = 0;
	LL lastpush = 0;
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		h[i] = a;
	}
	sort(h, h + n);
	LL now = 0LL;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		if (h[i] > now) {
			ans += h[i] - 1;
			now++;
		} else {
			ans += h[i] - 1;
		}
	}
	ans += min(now, h[n - 1] - 1);
	printf("%lld\n", ans);
 	return 0;
}
		