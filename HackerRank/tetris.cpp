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

bool dp[205][205][205];

void solve(string now, int left, int a, int b) {
	if (a < 0 || b < 0) return;
	if (dp[left][a][b] == 1) return;
	dp[left][a][b] = 1;
	if (left == 0) {
		if (a == 0 && b == 0) { 
			cout << now << endl;
			exit(0);
		}
	} else {
		solve(now + "SS", left - 1, a - 2, b);
		solve(now + "SRS", left - 1, a - 2, b - 1);
		solve(now + "RR", left - 1, a, b - 2);
		solve(now + "RSR", left - 1, a - 1, b - 2);
	}
}

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	solve("", n, a, b);
	cout << "TIDAK MUNGKIN" << endl;
	return 0;
}
		