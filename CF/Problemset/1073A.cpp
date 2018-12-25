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
	int n;
	string s;
	cin >> n >> s;
	bool fnd = 0;
	string ans;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			fnd = 1;
			ans.pb(s[i - 1]); ans.pb(s[i]);
			break;
		}
	}
	if (fnd) {	
		cout << "YES\n" << ans << endl;
	} else 
		cout << "NO\n";
	return 0;
}
		