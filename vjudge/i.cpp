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

string s;
int t;
vector<int> v;

int main() {
	scanf("%d", &t);
	while (t--) {
		v.clear();
		cin >> s;
		int now = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ']') {
				if (now == -1) continue;
				else v.pb(now);
				now = -1;
			} else if ('0' <= s[i] && s[i] <= '9') {
				if (now == -1) {
					now = s[i] - '0';
				} else now = now * 10 + s[i] - '0';
			}
		}
		sort(all(v));
		int len = v.size();
		len = (len >> 1) + 1;
		LL ans = 0;
		for (int i = 0; i < len; i++) {
			ans += (v[i] >> 1) + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
		