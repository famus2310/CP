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

list<LL> vin[1005];
list<LL> vout[1005];
LL n, m;

int main() {
	cin >> n >> m;
	LL oddDegree = 0;
	for (int i = 0; i < m; i++) {
		LL u, v;
		cin >> u >> v;
		vout[u].pb(v);
		vin[v].pb(u);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		LL out = vout[i].size();
		LL in = vin[i].size();
		ans += max(out - in, 0LL);
	}
	cout << ans << endl;
	return 0;
}
