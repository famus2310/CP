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

int mx = -1;
int n;
bool fr[25][25];

void dfs(int now, vector<int> v) {
	if (now == n) {
		int len = v.size();
		mx = max(mx, len);
		bool flag = 1;
		for (int i = 0; i < v.size(); i++) {
			if (!fr[v[i]][now]) {
				flag = 0;
				break;
			}
		}
		if (flag) mx = max(mx, len + 1);
		return;
	}
	dfs(now + 1, v);
	bool flag = 1;
	for (int i = 0; i < v.size(); i++) {
		if (!fr[v[i]][now]) {
			flag = 0;
			break;
		}
	}	
	if (flag) v.pb(now);
	dfs(now + 1, v);
}

int main() {
	int m;
	memset(fr, 0, sizeof(fr));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		fr[u][v] = fr[v][u] = 1;
	}
	dfs(1, {});
	printf("%d\n", mx);
	return 0;
}
		