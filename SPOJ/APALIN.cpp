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

string s1, s2;
LL dp[10005][2];

LL solve() {
	SET(dp, 0);
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			int fly = i & 1;
			if (s1[i - 1] == s2[j - 1])
				dp[j][fly] = dp[j - 1][fly ^ 1] + 1;
			else 
				dp[j][fly] = max(dp[j - 1][fly], dp[j][fly ^ 1]);
		}
	}
	return dp[s2.size()][(s1.size()) & 1];
}

int main() {
	int n;
	cin >> n;
	cin >> s1;
	s2 = s1;
	reverse(all(s2));
	cout << s1.size() - solve() << endl;
	return 0;
}
		
/*
bccc3
3cccb
*/