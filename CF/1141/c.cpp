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

LL diff[2 * N];
bool vis[3 * N];

int main() {
	LL n;
	scanf("%lld", &n);
	LL mn = 0;
	LL now = 0;
	for (LL i = 0; i < n - 1; i++) {
		LL a;
		scanf ("%lld", &a);
		diff[i] = a;
		now = now + a;
		mn = min(mn, now);
	}
	vector<LL> ans;
	LL x = 1 - mn;
	if (x < 0 || x > n) {
		puts("-1");
		return 0;
	}
	ans.pb(x);
	vis[x] = 1;
	bool err = 0;
	for (LL i = 0; i < n - 1; i++) {
		x = x + diff[i];
		if (x > n || x < 0) {
			puts("-1");
			return 0;
		}
		if (vis[x]) {
			puts("-1");
			return 0;
		}
		vis[x] = 1;
		ans.pb(x);
	}
	for (LL i = 1; i <= n; i++) {
		if (!vis[i]) {
			puts("-1");
			return 0;
		}
	}
	for (LL it : ans)
		cout << it << " ";
	puts("");
	return 0;
}
