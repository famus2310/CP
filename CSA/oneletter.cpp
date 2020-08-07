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

const int NMAX = 1e5 + 5;


int main() {
	int t;
	cin >> t;
	string ans;
	while (t--) {
		string s;
		cin >> s;
		char last = 'z';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < last) last = s[i];
		}
		ans.pb(last);
	}
	sort(all(ans));
	cout << ans << endl;
	return 0;
}
		