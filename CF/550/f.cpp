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

int color[2 * N]; //0 = uncolored, 1 = red, 2 = blue
vector<int> adjList[2 * N];
vector<pair<int, int> > edgeList;

bool isBipartite(int now, int lastCol) {
	if (lastCol == 1)
		color[now] = 2;
	else color[now] = 1;
	bool ret = 1;
	for (auto it : adjList[now]) {
		if (color[it] == 0) 
			ret &= isBipartite(it, color[now]);
		else if (color[it] != color[now])
			continue;
		else return 0;
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[a].pb(b);
		adjList[b].pb(a);
		edgeList.pb({a, b});
	}
	if (isBipartite(1, 1)) {
	// for (int i = 1; i <= n; i++) {
	// 	cout << color[i] << endl;
	// }
		puts("YES");
		for (int i = 0; i < m; i++) {
			if (color[edgeList[i].first] == 1)
				printf("0");
			else printf("1");
		}
		puts("");
	} else puts("NO");
	return 0;
}
		