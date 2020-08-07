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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

bool vis[256];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		string s;
		cin >> s;
		// s.erase(it, s.end());
		string ans;
		for (char c : s) {
			if (vis[c]) continue;
			vis[c] = 1;
			ans.pb(c);
		}
		cout << ans << endl;
	}
	return 0;
}
		