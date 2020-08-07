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

int E[2 * N], L[2 * N], H[2 * N];
int table[2 * N][25]; 
int LOG[2 * N];
vector<int> adjList[N];
int idx = 0;
bool vis[N];

void euler_tour(int now, int level) {
	vis[now] = 1;
	if (H[now] == -1) H[now] = idx;
	E[idx] = now;
	L[idx] = level;
	idx++;
	for (int it : adjList[now]) {
		if (vis[it]) continue;
		euler_tour(it, level + 1);
		E[idx] = now;
		L[idx] = level;
		idx++;
	}
	vis[now] = 0;
}

void build(int n) {
	for (int i = 0; i < n; i++) {
		table[i][0] = i;
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			if (L[table[i][j - 1]] < L[table[i + (1 << (j - 1))][j - 1]])
				table[i][j] = table[i][j - 1];
			else 
				table[i][j] = table[i + (1 << (j - 1))][j - 1];
		}
	}
}

int query(int a, int b) {
	if (a > b) swap(a, b);
	int j = LOG[b - a + 1];
	if (L[table[a][j]] < L[table[b - (1 << j) + 1][j]])
		return table[a][j];
	return table[b - (1 << j) + 1][j];
}

void preprocess() {
	LOG[1] = 0;
	for (int i = 2; i < 2 * N; i++)
		LOG[i] = LOG[i >> 1] + 1;
}

void solve(int x, int y) {
	int idxx = H[x];
	int idxy = H[y];
	int ansid = query(idxx, idxy);
	int node = E[ansid];
	if (node == x) 
		puts("TIDAK");
	else 
		puts("YA");
}

int main() {
	memset(H, -1, sizeof H);
	preprocess();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d" , &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	euler_tour(1, 1);
	// debug("cuk");
	build(idx);
	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		solve(x, y);
	}
	return 0;
}
		