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

vector<int> v;
map<int, int> cnt;

int dfs(int now, int cur) {
	// debug(now);
	int ret = 0;
	int lb = lower_bound(v.begin() + cur, v.end(), now) - v.begin();
	if (lb == v.size()) return 0;
	ret = now + dfs(now * 2, lb + 1);
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	for (auto it : cnt)
		v.pb(it.second);
	sort(all(v));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int lb = lower_bound(all(v), i) - v.begin();
		if (lb == v.size()) break;	
		ans = max(ans, i + dfs(i * 2, lb + 1));
	}
	printf("%d\n", ans);
	return 0;
}
		