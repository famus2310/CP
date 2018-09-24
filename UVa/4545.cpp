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


int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> adjList[n + 1];
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		queue<int> ans;
		for (int i = 1; i <= n; i++) {
			if (adjList[i].size() < 2) ans.push(i);
		}
		if (ans.size() & 1) 
			ans.push(ans.front() % n + 1);
		printf("%d\n", (int)ans.size() / 2);
		while (!ans.empty()) {
			printf("%d", ans.front());
			ans.pop();
			printf(" %d\n", ans.front());
			ans.pop();
		}
		puts("");
	}
	return 0;
}
		