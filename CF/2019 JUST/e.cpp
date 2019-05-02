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

int cost[35];
string s;
string p;

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 35; i++)
			cost[i] = INF;
 		int n, m;
		cin >> n >> m;
		cin >> s;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			cost[s[i] - 'a'] = min(cost[s[i] - 'a'], c - '0');
		}
		LL ans = 0LL;
		bool isvalid = 1;
		for (int i = 0; i < m; i++) {
			char c;
			cin >> c;
			if (cost[c - 'a'] == INF)
				isvalid = 0;
			ans = ans + cost[c - 'a'];
		}
		if (!isvalid)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}
		