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


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		string ans;
		for (int i = s.size() - 2; i >= 0; i -= 2) {
			ans.pb(s[i]);
		}
		for (int i = (s.size() & 1 ? 0 : 1); i < s.size(); i += 2) {
			ans.pb(s[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
		