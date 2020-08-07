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

int n, m, k;

vector<int> adjList[N];
bool vis[N];

void dfs(int now) {
	vis[now] = 1;
	for (auto it : adjList[now]) {
		if (!vis[it]) {
			dfs(it);
		}
	}
}

int main() {
	fastio;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt -  1 << endl;
	return 0;
}
		