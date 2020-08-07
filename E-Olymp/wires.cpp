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

LL n, k;
LL arr[10005];

LL check(LL x) {
	LL ret = 0LL;
	for (int i = 0; i < n; i++)
		ret = ret + arr[i] / x;
	return ret;
}

int main() {
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	LL hi = 10000000;
	LL lo = 1;
	while (hi - lo > 1) {
		LL mid = lo + (hi - lo) / 2;
		if (check(mid) < k) {
			hi = mid;
		} else
			lo = mid;
	}
	LL ans = 0;
	if (lo > hi)
		swap(lo, hi);
	for (; hi >= lo; hi--) {
		if (check(hi) >= k) {
			ans = hi;
			break;
		}
	}
	// assert(ans != 0);
	cout << ans << endl;
	return 0;
}
		