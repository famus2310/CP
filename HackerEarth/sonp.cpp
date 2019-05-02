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

LL n, m, k;
vector<LL> adjList[N];
LL deg[N];
bool vis[N];

struct node {
	LL a, b;
	node operator+(const node& other) const {
		node tmp;
		tmp.a = a + other.a;
		tmp.b = b + other.b;
		return tmp;
	}
};

node dfs(LL now) {
	node ret = {1LL, deg[now]};
	for (auto it : adjList[now]) {
		if (!vis[it]) {
			vis[it] = 1;
			ret = ret + dfs(it);
		}
	}
	return ret;
}

int main() {
	SET(deg, 0);
	fastio;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		LL a, b;
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	int comp = 0;
	LL removed = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			comp++;
			node cur = dfs(i);
			removed = removed + cur.b / 2 - cur.a + 1;
		}
	} 
	if (comp > k) {
		cout << "-1" << endl;
	} else {
		cout << removed + (k - comp) << endl;
	}
	return 0;
}
		