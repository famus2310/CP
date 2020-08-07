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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int n;
int arr[N];
int dp[N][7];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);	
		if (i == 0) {
			for (int j = 1; j <= 5; j++)
				dp[i][j] = 1;
		} else {
			if (arr[i] > arr[i - 1]) {
				dp[i][1] = 0;
				for (int j = 2; j <= 5; j++) {
					if (dp[i - 1][j - 1] == 1 || dp[i][j - 1] == 1)
						dp[i][j] = 1;
					else dp[i][j] = 0; 
				}
			} else if (arr[i] < arr[i - 1]) {
				dp[i][5] = 0;
				for (int j = 4; j > 0; j--) {
					if (dp[i - 1][j + 1] == 1 || dp[i][j + 1] == 1)
						dp[i][j] = 1;
					else dp[i][j] = 0; 
				}
			} else if (arr[i] == arr[i - 1]) {
				for (int j = 1; j <= 5; j++)
					dp[i][j] = 0;
				for (int j = 1; j <= 5; j++) {
					if (dp[i - 1][j] == 1) {
						for (int k = 1; k <= 5; k++) {
							if (k == j) continue;
							dp[i][k] = 1;
						}
					}
				}
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 1; j <= 5; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	vector<int> v;
	for (int i = 5; i >= 0; i--) {
		if (dp[n - 1][i]) {
			v.pb(i);
			break;
		}
	}
	if (v.empty()) {
		puts("-1");
		exit(0);
	}
	for (int i = n - 2; i >= 0; i--) {;
		int ans = -1;
		if (arr[i + 1] < arr[i]) {
			for (int j = v.back() + 1; j <= 5; j++) {
				if (dp[i][j] == 1) {
					ans = j;
					break;
				}
			}
		} else if (arr[i + 1] > arr[i]) {
			for (int j = v.back() - 1; j > 0; j--) {
				if (dp[i][j] == 1) { 
					ans = j;
					break;
				}
			}
		} else if (arr[i + 1] == arr[i]) {
			for (int j = 5; j > 0; j--) {
				if (j == v.back()) continue;
				if (dp[i][j] == 1) {
					ans = j;
					break;
				}
			}
		}
		v.pb(ans);
	}
	reverse(all(v));
	for (int it : v)
		cout << it << " ";
	cout << endl;
	return 0;
}
		