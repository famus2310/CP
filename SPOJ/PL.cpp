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

int cnt[35];
string s;

int main() {
	int t;
	scanf("%d", &t);
	while (cin >> s) {
		memset(cnt, 0, sizeof cnt);
		int len = s.size();
		int odd = 0;
		for (int i = 0; i < len; i++) {
			cnt[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) if (cnt[i] & 1) odd++;
		if (len & 1) {
			if (odd == 1) puts("1");
			else puts("-1");
		} else {
			if (odd == 0) puts("1");
			else puts("-1");
		}
	}
	return 0;
}
		