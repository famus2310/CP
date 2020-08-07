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

double dp[1005][2]; //turn, iswin

int main() {
	fastio;
	cout << fixed << setprecision(6);
	int t;
	cin >> t;
	while (t--) {
		dp[0][0] = 1;
		double a = 0, b = 0;
		double r, g;
		cin >> r >> g;
		double all = r + g;
		if (r == 0) {
			cout << 1.0 << endl;
			continue;
		}
		for (int i = 1; i <= g + 1; i++) {
			dp[i][1] = dp[i - 1][0] * (r / (double)(all - i + 1));
			dp[i][0] = dp[i - 1][0] * (g / (double)(all - i + 1));
			if (i & 1)
				a = a + dp[i][1];
			else b = b + dp[i][1];
		}
		cout << a << " " << b << endl;
		cout << 1 - b << endl;
		cout << "sum : " << a + b << endl;
	}
	return 0;
}
		