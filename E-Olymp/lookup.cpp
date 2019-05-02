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

vector<double> v;
double dp[50][50];
double opt[50][50];

string solve(int a, int b) {
	if (a == b)
		return to_string(v[a]);
	int k = opt[a][b];
	return "(" + solve(a, k) + ")(" + solve(k + 1, b) + ")";
}

int main() {
	fastio;
	v.pb(1000);
	v.pb(1100);
	v.pb(1200);
	v.pb(1300);
	// v.pb(5);
	// v.pb(6);
	// v.pb(2000.0);
	// v.pb(2200.0);
	// v.pb(2400.0);
	// v.pb(2600.0);
	double mx = 0;
	vector<double> conf;
	// do {
		
		double now = 0;
		for (int i = 0; i < v.size(); i++)
			dp[i][i] = v[i];
		for (int i = 2; i <= v.size(); i++) {
			for (int j = 0; j + i - 1 < v.size(); j++) {
				int lf = j;
				int rg = j + i - 1;
				dp[lf][rg] = 0;
				for (int k = lf; k < rg; k++) {
					if (dp[lf][rg] < (dp[lf][k] + dp[k + 1][rg]) * 95.0 / 100.0) {
						dp[lf][rg] = (dp[lf][k] + dp[k + 1][rg]) * 95.0 / 100.0;
						opt[lf][rg] = k;
					}
					// dp[lf][rg] = max(dp[lf][rg], (dp[lf][k] + dp[k + 1][rg]) * 95.0 / 100.0);
				}
				// cout << dp[i][j] << endl;
			}
		}
		// mx = max(mx, dp[0][v.size() - 1]);	
		// if (dp[0][v.size() - 1] < 18.55)
			// continue;
		// cout << solve(0, v.size() - 1) << endl;
		// for (auto it : v)
		// 	cout << it << " ";
		// cout << endl;
		cout << dp[0][v.size() - 1] << endl;;
	// } while (next_permutation(all(v)));
	cout << ((v[0] + v[1]) * 95.0 / 100 + (v[2]+ v[3]) * 95.0 / 100.0 ) * 95.0 / 100.0;
	// cout << ((dp[0][1] + dp[2][3]) * 95.0 / 100.0 + dp[4][4]) * 95.0 / 100.0 << endl;
	// cout << dp[]
	// int x, y;
	// while (1) {
	// 	cin >> x >> y;
	// 	cout << opt[x][y] << endl;
	// }
	// cout << dp[0][4] << endl;
	// mx = max(mx, dp[0][4]);
	// cout << dp[0][4] << endl;
	// for (auto it : v)
	// 	cout << it << " ";
	// cout << endl;
	// cout << "ANS: " << now << endl;
	// cout << endl;
	cout << mx << endl;
	return 0;
}
		