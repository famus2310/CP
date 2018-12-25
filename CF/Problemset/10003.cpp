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

int memo[1005][1005];

int cut[55];
int n;

int solve(int lo, int hi) {
	// cout << lo << " " << hi << endl;
	if (memo[lo][hi] != -1) 
		return memo[lo][hi];
	int ret = INF;
	int l = upper_bound(cut, cut + n, lo) - cut;
	for (int i = l; i < n; i++) {
		if (cut[i] <= lo) continue;
		if (cut[i] >= hi) break;
		ret = min(ret, hi - lo + solve(lo, cut[i]) + solve(cut[i], hi));
	}
	if (ret == INF) return memo[lo][hi] = 0;
	return memo[lo][hi] = ret;
}

int main() {
	int l;
	while (scanf("%d", &l)) {
		if (l == 0) break;
		scanf("%d", &n);
		SET(memo, -1);
		for (int i = 0; i < n; i++) {
			scanf("%d", cut + i);
		}
		printf("The minimum cutting is %d.\n", solve(0, l));
	}
	return 0;
}
		