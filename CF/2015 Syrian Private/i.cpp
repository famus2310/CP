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

int cnt[35];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(cnt, 0);
		string s;
		cin >> s;
		for (char c : s)
			cnt[c - 'a']++;
		int odd = 0;
		char codd;
		for (int i = 0; i < 35; i++) {
			if (cnt[i] & 1) {
				odd++;
				codd = i + 'a';
			}
		}
		if (odd > 1)
			puts("impossible");
		else {
			string ans;
			for (int i = 0; i < 35; i++) {
				while (cnt[i] > 1) {
					ans.pb(i + 'a');
					cnt[i] -= 2;
				}
			}
			string ret = ans;
			if (s.size() & 1) ret.pb(codd);
			for (int i = ans.size() - 1; i >= 0; i--)
				ret.pb(ans[i]);
			cout << ret << endl;
		}
	}
	return 0;
}
		