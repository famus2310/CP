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

map<LL, LL> dist;

LL bfs(LL src, LL dest) {
	queue<LL> q;
	q.push(src);
	dist[src] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == dest)
			return dist[now] - 1;
		if (now * 2 <= dest && dist.find(now * 2) == dist.end()) {
			dist[now * 2] = dist[now] + 1;
			q.push(now * 2);
		}
			if (now * 3 <= dest && dist.find(now * 3) == dist.end()) {
			dist[now * 3] = dist[now] + 1;
			q.push(now * 3);
		}
	}
	return -1;
} 

int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld\n", bfs(n, m));
	return 0;
}
		