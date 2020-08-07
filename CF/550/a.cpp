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

bool vis[35];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		SET(vis, 0);
		string s;
		cin >> s;
		sort(all(s));
		bool ans = 1;
		vis[s[0] - 'a'] = 1;
		for (int i = 1; i < s.size(); i++) {
			if (abs(s[i] - 'a' - (s[i - 1] - 'a')) > 1 || abs(s[i] - 'a' - (s[i - 1] - 'a')) == 0)
				ans = 0;
		}
		if (ans)
			puts("Yes");
		else puts("No");
	}
	return 0;
}
		