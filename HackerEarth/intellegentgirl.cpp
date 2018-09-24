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

const int N = 1e4 + 5;

LL t, n;
LL dp[N];

int main() {
	string s;
	cin >> s;
	dp[0] = 0;
	for (int i = 1; i <= s.size(); i++) {
		dp[i] = dp[i - 1];
		if ((s[i - 1] - '0') % 2 == 0) dp[i]++;
	}
	for (int i = 1; i <= s.size(); i++) {
		if (i != 1) cout << " ";
		cout << dp[s.size()] - dp[i - 1];	
	}
	cout << endl;
	return 0;
}
		