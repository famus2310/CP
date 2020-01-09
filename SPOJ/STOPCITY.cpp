#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

vector<int> adj[10005];
vector<pair<int, int> > bridges;
vector<int> adjComp[10005];
bool visited[10005];
bool visitedComp[10005];
int tin[10005], low[10005];
int timer;
int root[10005];
vector<int> comp;
int compNum[10005];
vector<int> ans;
bool getAns = 0;
int src, dst;

int findRoot(int a) {
	return root[a] == a ? a : root[a] = findRoot(root[a]);
}

void uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	if (root_a != root_b) {
		root[root_a] = root_b;
	}
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.pb({to, v});
                continue;
            }
        }
        compNum[to] = compNum[v] = comp.size();
        uni(to, v);
    }
}


void dfsComp(int now, int par = -1) {
	visitedComp[now] = 1;
	if (now == dst) { 
		getAns = 1;
		return;
	}
	for (auto it : adjComp[now]) {
		if (it == par)
			continue;
		dfsComp(it, now);
		if (getAns)
			return;
	}
	visitedComp[now] = 0;
}



int main() {
	NeedForSpeed;
	timer = 0;
	SET(tin, -1);
	SET(low, -1);
	SET(compNum, -1);
	int n;
	cin >> n;
	int a, b;
	while (cin >> a) {
		cin >> b;
		if (a == -1 && b == -1)
			break;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
			int curRoot = findRoot(i);
			comp.pb(curRoot);
		}
		cout << i << " : " << compNum[i] << endl;
	}
	for (auto it : bridges) {
		int comp_a = compNum[it.first];
		int comp_b = compNum[it.second];
		cout << comp_a << " " << comp_b << endl;
		adjComp[comp_a].pb(comp_b);
		adjComp[comp_b].pb(comp_a);
	}
	dfsComp(src);
	bool fi = 0;
	for (int i = 0; i < n; i++) {
		if (visitedComp[compNum[i]]) {
			if (!fi)
				cout << " ";
			fi = 0;
			cout << i; 
		}
	}
	cout << endl;

	return 0;
}
		