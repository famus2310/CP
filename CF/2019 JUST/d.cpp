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

// string s[3];
// bool vis[15];
LL dp[15][15][15][15]; //n, a, b, c


int main() {
	// auto y = clock();
	int t;
	cin >> t;
	while (t--) {
		string s;
		int a = 0, b = 0, c = 0;
		cin >> s;
		for (char x : s) {
			if (x == '1')
				a++;
		}
		cin >> s;
		for (char x : s) {
			if (x == '1')
				b++;
		}
		cin >> s;
		for (char x : s) {
			if (x == '1')
				c++;
		}
		SET(dp, -1);
		dp[0][a][b][c] = 0;
		for (int i = 1; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				for (int k = 0; k < 12; k++) {
					for (int l = 0; l < 12; l++) {
						if (dp[i - 1][j + 1][k + 1][l + 1] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j + 1][k + 1][l + 1] + (1LL << (i - 1)), dp[i][j][k][l]);
						if (dp[i - 1][j + 1][k][l] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j + 1][k][l] + (1LL << (i - 1)), dp[i][j][k][l]);
						if (dp[i - 1][j][k + 1][l] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j][k + 1][l] + (1LL << (i - 1)), dp[i][j][k][l]);
						if (dp[i - 1][j][k][l + 1] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j][k][l + 1] + (1LL << (i - 1)), dp[i][j][k][l]);
						if (dp[i - 1][j + 2][k][l] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j + 2][k][l], dp[i][j][k][l]);
						if (dp[i - 1][j][k + 2][l] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j][k + 2][l], dp[i][j][k][l]);
						if (dp[i - 1][j][k][l + 2] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j][k][l + 2], dp[i][j][k][l]);
						if (dp[i - 1][j + 1][k + 1][l] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j + 1][k + 1][l], dp[i][j][k][l]);
						if (dp[i - 1][j + 1][k][l + 1] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j + 1][k][l + 1], dp[i][j][k][l]);
						if (dp[i - 1][j][k + 1][l + 1] != -1)
							dp[i][j][k][l] = max(dp[i - 1][j][k + 1][l + 1], dp[i][j][k][l]);
						if (dp[i - 1][j][k][l] != -1)
							dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l]);
					}
				}
			}
		}
		bitset<10> bs(dp[10][0][0][0]);
		cout << bs << endl;
		// cout << dp[10][0][0][0] << endl;
 	// 	vector<int> perm = {0, 1, 2};
	// 	cin >> s[0];
	// 	cin >> s[1];
	// 	cin >> s[2];
	// 	string ret = "0000000000";
	// 	do {
	// 		string ans = "0000000000";
	// 		int a = 0, b = 0, c = 0;
	// 		for (char x : s[perm[0]]) {
	// 			if (x == '1')
	// 				a++;
	// 		}
	// 		for (char x : s[perm[1]]) {
	// 			if (x == '1')
	// 				b++;
	// 		}
	// 		for (char x : s[perm[2]]) {
	// 			if (x == '1')
	// 				c++;
	// 		}
	// 		SET(vis, 0);
	// 		for (int i = 0; i < 10 && a > 0; i++) {
	// 			ans[i] = '1';
	// 			a--;
	// 		}
	// 		for (int i = 0; i < 10 && b > 0; i++) {
	// 			if (ans[i] == '0') {
	// 				ans[i] = '1';
	// 				b--;
	// 				vis[i] = 1;
	// 			} 
	// 		}
	// 		for (int i = 9; i >= 0 && b > 0; i--) {
	// 			if (!vis[i]) {
	// 				ans[i] = '0';
	// 				b--;
	// 			}
	// 		}
	// 		SET(vis, 0);
	// 		for (int i = 0; i < 10 && c > 0; i++) {
	// 			if (ans[i] == '0') {
	// 				ans[i] = '1';
	// 				c--;
	// 				vis[i] = 1;
	// 			}
	// 		}
	// 		for (int i = 9; i >= 0 && c > 0; i--) {
	// 			if (!vis[c]) {
	// 				ans[i] = '0';
	// 				c--;
	// 			}
	// 		}
	// 		ret = max(ans, ret);
	// 		cout << ans << endl;
	// 	} while (next_permutation(all(perm)));
	// 	cout << ret << endl;
	}
	// cout << double(clock() - y) / CLOCKS_PER_SEC << endl;
	return 0;
}
		