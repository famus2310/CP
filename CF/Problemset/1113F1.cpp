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

const int N = 2e5 + 5;

vector<int> adjList[N];
int edgeCnt[N];
bool vis[N];

vector<pair<int, int> > ans;

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto it : adjList[now]) {
			if (!vis[it]) {
				vis[it] = 1;
				ans.pb({now, it});
				q.push(it);
			}
		}
	}
}

int main() {
	SET(edgeCnt, 0);
	int mxCnt = 0;
	int mxEdge;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
		edgeCnt[u]++;
		edgeCnt[v]++;
		if (edgeCnt[u] > mxCnt) {
			mxCnt = edgeCnt[u];
			mxEdge = u;
		}
		if (edgeCnt[v] > mxCnt) {
			mxCnt = edgeCnt[v];
			mxEdge = v;
		}
	}
	bfs(mxEdge);
	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}

	return 0;
}
		