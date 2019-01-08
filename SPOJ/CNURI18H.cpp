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
const int MAXLEVEL = 18;

int par[N];
int parent[N][MAXLEVEL];
int depth[N];
int rk[N];
int heavyEdge[N][MAXLEVEL];
vector<piii> edgeList;
vector<pii> adjList[N];
int n, m;

void dfs(int now, int prev) {
	if (now != 0) {
		depth[now] = depth[prev] + 1;
		parent[now][0] = prev;
	}
	for (auto it : adjList[now]) {
		if (it.first != prev) {
			heavyEdge[it.first][0] = it.second;
			dfs(it.first, now);
		}
	}
}
 
int findRoot(int x) {
	return x == par[x] ? x : par[x] = findRoot(par[x]);
}

bool uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	if (root_b == root_a)
		return false;
	else {
		if (rk[root_a] >= rk[root_b]) {
			par[root_b] = root_a;
			rk[root_a] += (rk[root_a] == rk[root_b]);
		} else {
			par[root_a] = root_b;
		}
		return true;
	}
}

void preprocess() {
	for (int i = 0; i < n; i++)
		par[i] = i;
}

void kruskal() {
	for (int i = 0; i < edgeList.size(); i++) {
		int x = edgeList[i].second.first;
		int y = edgeList[i].second.second;
		int w = edgeList[i].first;
		if (uni(x, y)) {
			adjList[x].pb({y, w});
			adjList[y].pb({x, w});
		}
	}
}

void build() {
	for (int i = 1; i < MAXLEVEL; i++) {
		for (int j = 0; j < N; j++) {
			if (parent[j][i - 1] != -1) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				heavyEdge[j][i] = max(heavyEdge[j][i - 1], heavyEdge[parent[j][i - 1]][i - 1]);
			}
		}
	}
}

int LCA(int u, int v) {
	if (depth[v] < depth[u]) 
		swap(u, v); 
	int diff = depth[v] - depth[u]; 
	for (int i = 0; i < MAXLEVEL; i++) 
  	if ((diff >> i) & 1) 
      v = parent[v][i]; 
  if (u == v) 
      return u; 
  for (int i = MAXLEVEL - 1; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) { 
      u = parent[u][i]; 
      v = parent[v][i]; 
    } 
  }
  return parent[u][0]; 
} 

int findHeavy(int now, int curDepth) {
	int ret = 0;
	for (int i = MAXLEVEL - 1; i >= 0; i--) {
		if (curDepth >= (1 << i)) {
			ret = max(ret, heavyEdge[now][i]);
			now = parent[now][i];
			curDepth -= (1 << i);
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	SET(parent, -1);
	preprocess();
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edgeList.pb({c, {a, b}});
	}
	sort(all(edgeList));
	kruskal();
	int q;
	scanf("%d", &q);
	depth[0] = 0;
	dfs(0, 0);
	build();
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int curLCA = LCA(a, b);
		int ans = max(findHeavy(a, depth[a] - depth[curLCA]), findHeavy(b, depth[b] - depth[curLCA]));
		printf("%d\n", ans); 
	}
	return 0;
}
		