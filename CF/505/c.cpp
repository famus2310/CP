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
int dp[N][2]; //0 = w, 1 = b

int main() {
	memset(dp, 0, sizeof(dp));
	cin >> s;
	bool bfi = 1, blast = 1;
	int fi = 0;
	char cfi = s[0];
	int last = s.size() - 1;
	char clast = s[s.size() - 1];
	if (s[0] == 'w') dp[0][0]++;
	else dp[0][1]++;
	int mx = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != cfi && bfi) {
			cfi = s[i];
			fi = i;
		} else bfi = 0;
		if (s[i] == 'w') {
			dp[i][0] = dp[i - 1][1] + 1;
			dp[i][1] = 0;
		} else {
			dp[i][1] = dp[i - 1][0] + 1;
			dp[i][0] = 0;
		}
		mx = max(mx, max(dp[i][1], dp[i][0]));
	}
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s[i] != clast && blast) {
			clast = s[i];
			last = i;
		} else blast = 0;
	}
	if (s[0] == s[s.size() - 1]) {
		printf("%d\n", mx);
	} else {
		if (fi < last) {
			int tmp = s.size();
			mx = max(mx, fi + 1 + tmp - last);
			printf("%d\n", mx);
		} else {
			int tmp = s.size();
			printf("%d\n", tmp);
		}
	}
	return 0;
}
		