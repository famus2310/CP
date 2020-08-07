#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

enum {RED = 1, BLUE = 2};

int color[N];
int n, m;
vector<int> adjList[N];

bool dfs(int now, int cur) {
	color[now] = cur;
	for (auto it : adjList[now]) {
		if (!color[it]) {
			if(!dfs(it, cur == RED ? BLUE : RED))
				return false;
		}
		else if (color[it] == cur) 
			return false;
	}
	return true;
}

bool isBipartite() {
	for (int i = 1; i <= n; i++)
		color[i] = 0;
	for (int i = 1; i <= n; i++) 
		if (!color[i]) {
			if (!dfs(i, RED)) 
				return false;
		}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u , &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	printf("%s\n", isBipartite() ? "YA" : "TIDAK");
	return 0;
}
		