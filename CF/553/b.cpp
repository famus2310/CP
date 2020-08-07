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

int matrix[505][505];
pair<int, int> dp[1025][505];
vector<int> ans;

void search(int cur, int col) {

	// debug(cur);
	if (col == 0)
		return;
	ans.pb(dp[cur][col].second);
	search(dp[cur][col].first, col - 1);
}


int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < 1025; i++)
		for (int j = 0; j < 505; j++)
			dp[i][j] = {-1, -1};

	dp[0][0] = {0, 0};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 1025; k++) {
				if (dp[k][i - 1].first != -1)
					dp[k ^ matrix[i][j]][i] = {k, j};
			}
		}
	}
	for (int i = 1; i < 1025; i++) {
		if (dp[i][n].first != -1) {
			cout << "TAK" << endl;
			search(i, n);
			for (auto it : ans)
				cout << it <<" " ;
			return 0;
		}
	}
	cout << "NIE" << endl;
	return 0;
}
		