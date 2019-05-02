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

LL arr[1005];

int main() {
	LL n, h;
	scanf("%lld %lld", &n, &h);
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
	}
	LL ans = 0;
	LL i = 0;
	while (i < n) {
		LL now1 = arr[i];
		if (now1 <= h)
			ans++;
		if (i + 1 >= n)
			break;
		LL now2 = arr[i + 1];
		if (now2 <= h) {
			ans++;
		}
		h -= max(now1, now2);
		i = i + 2;
	}
	printf("%lld\n", ans);
	return 0;
}
		