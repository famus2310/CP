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


int main() {
	string s;
	while (getline(cin, s)) {
		bool commented = 0;
		string ans;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-' && i + 1 < s.size() && s[i + 1] == '>') {
				ans += ".";
				i++;
			} else if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '/') {
				ans += s.substr(i);
				break;
			} else 
				ans.pb(s[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
		