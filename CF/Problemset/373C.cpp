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

const int N = 5e5 + 5;

multiset<int> ms;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		ms.insert(a);
	}
	LL ans = 0LL;
	while (!ms.empty()) {
		auto it = ms.end();
		it--;
		int now = *it;
		// debug(now);
		ms.erase(it);
		auto ub = ms.upper_bound(now / 2);
		
		ans++;
		if (ms.empty()) break;
		if (ub != ms.begin()) {
			ub--;
			ms.erase(ub);
		} else if (*ub <= now / 2) {
			ms.erase(ub);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
		