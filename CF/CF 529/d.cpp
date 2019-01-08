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

vector<int> adjList[2 * N];
bool vis[2 * N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[i].pb(b);
		adjList[i].pb(a);
	}
	int now = 1;
	vis[1] = 1;
	cout << 1 << " ";
	while (true) {
		// cout << adjList[now][0] << " " <<adjList[now][1] << endl;;
		if (vis[adjList[now][0]] && vis[adjList[now][1]])
			break;
		if (vis[adjList[now][0]] && !vis[adjList[now][1]])
			now = adjList[now][1];
		else if (!vis[adjList[now][0]] && vis[adjList[now][1]])
			now = adjList[now][0];
		else {
			int nxt1 = adjList[now][0];
			int nxt2 = adjList[now][1];
			if (adjList[nxt1][0] == nxt2 || adjList[nxt1][1] == nxt2) {
				now = nxt1;
			} else 
				now = nxt2;
		}
		cout << now << " ";
		vis[now] = 1;
	}
	cout << endl;
	return 0;
}
		