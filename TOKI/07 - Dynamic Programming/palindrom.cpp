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
LL dp[55][55];

int topDown(string s, int lo, int hi) {
	if (lo == hi) return dp[lo][hi] = 1;
	if (hi < lo) return 0;
	if (dp[lo][hi] != -1) return dp[lo][hi];
	if(s[hi] == s[lo]) {
		return dp[lo][hi] = 2 + topDown(s, lo + 1, hi - 1);
	}
	return dp[lo][hi] = max(topDown(s, lo + 1, hi), topDown(s, lo, hi - 1));
}

void init() {
	memset(dp, -1, sizeof(dp));
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		init();
		string s;
		cin >> s;
		LL tmp = topDown(s, 0, s.size() - 1);
		cout << tmp << endl;
	}
	return 0;
}
		