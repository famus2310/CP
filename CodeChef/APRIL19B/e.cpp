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

vector<int> adjList[N];
LL val[N];
LL modd[N];
LL g[N];
vector<int> leaf;

void dfs(int now, int par) {
	g[now] = (now == 1 ? val[1] : __gcd(g[par], val[now]));
	LL cntchild = 0;
	for (auto it : adjList[now]) {
		if (it == par)
			continue;
		dfs(it, now);
		cntchild++;
	}
	if (cntchild == 0) {
		leaf.pb(now);
	}
}


int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < N; i++)
			adjList[i].clear();
		leaf.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		for (int i = 1; i <= n; i++) 
			cin >> val[i];
		for (int i = 1; i <= n; i++)
			cin >> modd[i];
		dfs(1, -1);
		sort(all(leaf));
		for (int i = 0; i < leaf.size(); i++) {
			if (i > 0)
				cout << " ";
			LL it = leaf[i];
			LL x = __gcd(modd[it], g[it]);
			cout << modd[it] - x;
		}
		cout << endl;
	}
	return 0;
}
		