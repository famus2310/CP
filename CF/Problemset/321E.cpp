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

LL cost[4005][4005];
LL dp[4005][805];

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true;
	else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

LL solveCost(LL a, LL b) {
	// cout << cost[b][b] << cost[a - 1][b] << cost[a][b - 1] << cost[a - 1][a - 1] << endl;
	return (cost[b][b] - cost[a - 1][b] - cost[b][a - 1] + cost[a - 1][a - 1]) / 2;
}

void solve(LL k, LL lf, LL rg, LL optl, LL optr) {
	// cout << lf << " " << rg << endl;
	if (lf > rg)
		return;
	LL curOpt = INF64;
	LL idxOpt;
	LL mid = lf + (rg - lf) / 2;
	for (int i = optl; i <= mid && i <= optr; i++) {
		LL now = dp[i - 1][k - 1] + solveCost(i, mid);
		if (now < curOpt) {
			curOpt = now;
			idxOpt = i;
		}
	}
	dp[mid][k] = curOpt;
	solve(k, lf, mid - 1, optl, idxOpt);
	solve(k, mid + 1, rg, idxOpt, optr);
} 

int main() {
	LL n =readInt(), k = readInt();
	cost[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				cost[i][j] = 0;
				continue;
			}
			LL a = readInt();
			cost[i][j] = cost[i - 1][j] + cost[i][j - 1] - cost[i - 1][j - 1] + a;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = solveCost(1, i);
	}
	for (int i = 2; i <= k; i++) {
		solve(i, 1, n, 1, n);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
		}
	}
	printf("%lld\n", dp[n][k]);
	return 0;
}
		