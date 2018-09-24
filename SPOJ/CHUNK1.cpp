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

int t, n, m;
bool vis[10005];
vector<int> adjList[10005];
stack<int> st;

struct node{
	int val, idx;
	bool operator< (node const& other) const {
		if (val!= other.val)
			return val > other.val;
		return idx < other.idx;
	}
};

node soldier[10005];

void init() {
	for (int i = 0; i < 10005; i++) {
		soldier[i] = {0, i};
		adjList[i].clear();
	}
	while (!st.empty()) st.pop();
	memset(vis, 0, sizeof vis);
}

void dfs(int now) {
	vis[now] = 1;
	for (auto it : adjList[now]) {
		if (!vis[it]) 
			dfs(it);
	}
	st.push(now);
}

void topoSort() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	while (!st.empty()) {
		int now = st.top(); st.pop();
		for (auto it : adjList[now]) {
			soldier[it].val += soldier[now].val + 1;
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		init();
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adjList[u].pb(v);
		}
		topoSort();
		sort(soldier + 1, soldier + n + 1);
		// for (int i = 1; i <= n; i++) cout << soldier[i].val << " " << soldier[i].idx << endl;
		int mx = soldier[1].val;
		for (int i = 1; i <= n && soldier[i].val == mx; i++) {
			if (i != 1) printf(" ");
			printf("%d", soldier[i].idx);
		}
		puts("");
	}
	return 0;
}
		