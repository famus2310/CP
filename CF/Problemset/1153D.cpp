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

int n;
int dp[3 * N];//vertex number, transition = +- number of vertex
vector<int> depth[3 * N];
vector<int> child[3 * N];
bool maximize[3 * N];
int mxdepth = 0;
int leafcount = 0;
int countLeaf[3 * N];

int dfs(int x, int dep) {
	depth[dep].pb(x);
	int ret = 0;
	for (auto it : child[x]) {
		ret = ret + dfs(it, dep + 1);
	}
	if (child[x].size() == 0) {
		leafcount++;
		ret = 1;
	}
	mxdepth = max(mxdepth, dep);
	return countLeaf[x] = ret;
}

int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		maximize[i] = a;
		dp[i] = -INF;
	}
	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		child[a].pb(i);
	}
	countLeaf[1] = dfs(1, 0);
	for (int i = mxdepth; i >= 0; i--) {
		for (auto it : depth[i]) {
			if (child[it].size() == 0){
				dp[it] = leafcount;
				continue;
			}
			if (maximize[it]) {
				int cur = -INF;
				for (auto it2 : child[it]) {
					int now = dp[it2];
					cur = max(cur, now);
				}
				dp[it] = cur;
			} else {
				dp[it] = leafcount + 1 - countLeaf[it];
			}
			cout << it << " : " << dp[it] << endl;
		}
	}
	cout << dp[1] << endl;
	return 0;
}
		