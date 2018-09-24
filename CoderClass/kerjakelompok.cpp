#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

deque<LL> dq;

int main() {
	LL n;
	scanf("%lld", &n);
	for (LL i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		dq.pb(a);
	}
	sort(all(dq), greater<LL>());
	while (dq.size() > 1) {
		LL now1 = dq.front(); dq.pop_front();
		LL now2 = dq.back(); dq.pop_back();
		if (now1 > now2) {
			dq.push_front(now1 - now2);
		} else if (now1 < now2) {
			dq.push_back(now2 - now1);
		}
	}
	LL ans = dq.empty() ? 0 : dq.front();
	printf("%lld\n", ans);
	return 0;
}
// 3 3 2 - 0 1 1