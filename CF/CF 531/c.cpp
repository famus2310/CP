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

priority_queue<LL, vector<LL>, greater<LL> > pq;

int main() {
	LL n, x, y;
	scanf("%lld %lld %lld", &n, &x, &y);
	for (LL i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		pq.push(a);
	}
	LL ans = 0LL;
	if (x > y) {
		ans = n;
	} else if (x <= y) {
		while (!pq.empty() && pq.top() <= x) {
			ans++;
			pq.pop();
			if (!pq.empty()) {
				LL cur = pq.top() + y;
				pq.pop();
				pq.push(cur);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
		