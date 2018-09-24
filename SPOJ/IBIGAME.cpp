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

const int N = 1e2 + 5;

LL dp[N][N];
LL n;

LL check() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (dp[i][j] == -1) return 1;
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
	while (check()){
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (dp[i][j] != -1) continue;
				if (i < 2 && j < 2) {
					dp[i][j] = 1;
					dp[j][i] = 1;
					continue;
				}
				bool pending = 0;
				bool zero = 0;
				if (i >= 2) {
					for (int k = 2; k < 5 && i - k >= 0; k++) {
						if (dp[i - k][j + 1] == 1) zero = 1;
						else if (dp[i - k][j + 1] == -1) pending = 1;	
					}
				}
				if (j >= 2) {
					for (int k = 2; k < 5 && j - k >= 0; k++) {
						if (dp[i + 1][j - k] == 1) zero = 1;
						else if (dp[i + 1][j - k] == -1) pending = 1;
					} 
				}
				if (pending) continue;
				else if (zero) dp[i][j] = 0;
				else dp[i][j] = 1;
				dp[j][i] = dp[i][j];
				//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		puts("");
	}
	return 0;
}
		