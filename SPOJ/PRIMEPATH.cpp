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

bool notPrime[10005];
int vis[10005];

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; i < 10005; i++) {
		if (!notPrime[i]) {
			for (int j = i * i; j <= 10005; j += i)
				notPrime[j] = 1;
		}
	}
}

int change(int x, int pos, int y) {
	string tmp = to_string(x);
	tmp[pos] = (y + '0');
	return stoi(tmp);
}

int bfs(int src, int dst) {
	queue<int> q;
	vis[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == dst) return vis[now];
		for (int i = 0; i < 4; i++) {
			int fi = 0;
			if (i == 0)
				fi = 1;
			for (int j = fi; j <= 9; j++) {
				int tmp = change(now, i, j);
				if (!notPrime[tmp] && vis[tmp] == -1) {
					// cout << tmp << " ";
					q.push(tmp);
					vis[tmp] = vis[now] + 1;
				}
			}
		}
 	}
 	return -1;
}

int main() {
	sieve();
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(vis, -1);
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = bfs(a, b);
		if (ans == -1) puts("Impossible");
		else printf("%d\n", ans);
	}
	return 0;
}
		