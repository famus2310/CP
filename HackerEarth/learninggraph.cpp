#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

struct node {
	int val, idx;
	bool operator< (const node& other) const {
		if (val != other.val) return val > other.val;
		return idx > other.idx;
	}
};

int n, m, k;
vector<node> adj[1005];
int val[1005];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", val + i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].pb({val[b], b});
		adj[b].pb({val[a], a});
	}
	for (int i = 1; i <= n; i++) {
		// debug(adj[i].size());
		if (k > adj[i].size()) {
			puts("-1"); continue;
		}
		sort(all(adj[i]));		
		printf("%d\n", adj[i][k - 1].idx);
	}	
	return 0;
}
		