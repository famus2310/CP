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

string s, x;
int cnt[35];
int app[35];

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;
	int q;
	cin >> q;
	while (q--) {
		memset(app, 0, sizeof app);
		cin >> x;
		for (int i = 0; i < x.size(); i++) {
			app[x[i] - 'a']++;
		}
		int ans = INF;
		for (int i = 0; i < 26; i++) {
			if (app[i] == 0) continue;
			ans = min(ans, cnt[i] / app[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
		