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

LL n;
LL st[1005][11];
vector<int> child[1005];
LL depth[1005];

void dfs(int now) { 
	for (auto it : child[now]) {
		st[it][0] = now;
		depth[it] = depth[now] + 1;
		dfs(it);
	}
}

void build() {
	for (int j = 1; j < 11; j++) {
		for (int i = 1; i < 1005; i++) {
			if (st[i][j - 1] != -1)
				st[i][j] = st[st[i][j - 1]][j - 1];
		}
	}
}

LL solve(LL a, LL b) {
	if (depth[a] < depth[b])
		swap(a, b);
	LL diff = depth[a] - depth[b];
	for (int i = 0; i < 11; i++) {
		if ((1 << i) & diff)
			a = st[a][i];
	}

	if (b == a)	
		return b;

	for (int i = 10; i >= 0; i--) {
		if (st[b][i] != st[a][i]) {
			b = st[b][i];
			a = st[a][i];
		}
	}
	return st[b][0];
}

int main() {
	fastio;
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		SET(st, -1);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			child[i].clear();
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				LL a;
				cin >> a;
				child[i].pb(a);
			}
		}
		depth[1] = 1;
		st[1][0] = 0;
		dfs(1);
		build();
		int q;
		cin >> q;
		cout << "Case " << tc << ":" << endl;
		// cout << st[9][0] << endl;
		// cout << st[9][1] << endl;
		while (q--) {
			LL x, y;
			cin >> x >> y;
			cout << solve(x, y) << endl;
		}
	}
	return 0;
}
