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

set<LL> st;
bool vis[N];
map<LL, set<LL> > mp;

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		st.clear();
		mp.clear();
		memset(vis, 0, sizeof vis);
		LL n;
		scanf("%lld", &n);
		for (LL i = 1; i <= n; i++) {
			LL u, v;
			scanf("%lld %lld", &u, &v);
			st.insert(u);
			st.insert(v);
			mp[u].insert(i);
			mp[v].insert(i);
		}
		LL ans = 0LL;
		for (auto it : mp) {
			// debug(it.first);
			if (it.second.size() < 2) continue;
			LL cnt = 0LL;
			bool found = 0;
			for (LL i : it.second) {
				if (vis[i]) {
					found = 1;
				}
				if (!vis[i]) {
					vis[i] = 1;
					cnt++;
				}
			}
			if (!found) cnt--;
			// cout << it.first << " " << it.second.size() << endl;
			ans += (LL)it.first * (cnt);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		