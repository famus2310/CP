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

int arr[705];
vector<int> adj[705];
map<int, int> mp;
bool vis[705];

void bfs(int a) {
	queue<int> q;
	q.push(a);
	memset(vis, 0, sizeof vis);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		vis[now] = 1;
		for (int it : adj[now]) {
			if (!vis[it]) {
				q.push(it);
				vis[it] = 1;
			}
		}
	}
} 

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		mp[arr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (__gcd(arr[i], arr[j]) > 1) {
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	bfs(0);
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) flag = 0;
	}
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}
		