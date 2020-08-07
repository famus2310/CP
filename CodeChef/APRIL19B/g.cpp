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

bool isPalin[1005][1005];
LL dp[1005][1005];
LL dp1[1005][1005];
LL dp2[1005][1005];
LL cnt[1005][1005];
string s;

bool isPal(string s) {
	string tmp = s;
	reverse(all(s));
	return tmp == s;
}

int main() {
	cin >> s;
	int sz = s.size();
	if (sz == 1) {
		cout << 0 << endl;
		return 0;
	}
	assert(sz > 0);
	SET(dp, 0);
	for (int i = 0; i < sz; i++) {
		isPalin[i][i] = 1;
	}
	for (int i = 2; i <= sz; i++) {
		for (int j = 0; j + i - 1 < sz; j++) {
			int lf = j;
			int rg = j + i - 1;
			if (rg - lf == 1) {
				isPalin[lf][rg] = (s[lf] == s[rg]);
			} else
				isPalin[lf][rg] = isPalin[lf + 1][rg - 1] && (s[lf] == s[rg]);
			// cout << lf << " " << rg << " : " << isPalin[lf][rg] << endl;
		}
	}
	LL ans = 0LL;
	for (int i = 0; i < sz; i++) {
		dp2[i][i] = dp1[i][i] = 1;
	}
	for (int i = 2; i <= sz; i++) {
		for (int j = 0; j + i - 1 < sz; j++) {
			int lf = j;
			int rg = i + j - 1;
			if (s[lf] == s[rg]) {
				if (rg - lf > 1)
					dp[lf][rg] += dp1[lf + 1][rg - 1] + dp2[lf + 1][rg - 1];
				dp[lf][rg] += dp[lf + 1][rg - 1] + 1;
			}	
			dp1[lf][rg] = dp1[lf][rg - 1] + isPalin	[lf][rg];
			dp2[lf][rg] = dp2[lf + 1][rg] + isPalin	[lf][rg];
			ans = ans + dp[lf][rg];
			// cout << dp1[lf + 1][rg - 1] << endl;
			// cout << dp2[lf + 1][rg - 1] << endl;
			// cout << lf << " " << rg << " :  "<< endl;
			// cout << "dp : " << dp[lf][rg] << endl;
			// cout << "dp1 : " << dp1[lf][rg] << endl;
			// cout << "dp2 : " << dp2[lf][rg] << endl;
		}
	}
	// SET(cnt, 0);
	// int tmp = 0;
	// for (int i = 0; i < sz; i++) {
	// 	for (int j = i + 1; j < sz; j++) {
	// 		for (int szi = 1; i + szi - 1 < j; szi++) {
	// 			for (int szj = 1; j + szj - 1 < sz; szj++) {
	// 				string a = s.substr(i, szi);
	// 				string b = s.substr(j, szj);
	// 				if (isPal(a + b)) {
	// 					if (i == 0 && j + szj - 1 == 4)
	// 						cout << a << " " << b << endl;
	// 					cnt[i][j + szj - 1]++;
	// 					tmp++;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// cout << endl;
	// for (int i = 2; i <= sz; i++) {
	// 	for (int j = 0; j + i - 1 < sz; j++) {
	// 		int lf = j;
	// 		int rg = j + i - 1;
	// 		cout << lf << " " << rg << " : " << cnt[lf][rg] << endl;
	// 	}
 // 	}
	// cout << tmp << endl;
	cout << ans << endl;	
	return 0;
}
