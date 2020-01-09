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

int n, m, k;
int l[51][51];
vector<pair<int, int> > adjList[51];

struct node {
	int idx, cost, dist;
	bool operator<(const node& other) const {
		if (dist != other.dist)
			return dist > other.dist;
		return cost > other.cost;
	}
};

void dijkstra(int src) {
	vector<int> d(n + 1, INF);
	priority_queue<node> pq;
	pq.push({src, 0, 1});
	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if (now.cost < d[now.idx]) {
			d[now.idx] = now.cost;
			for (auto it : adjList[now.idx]) {
				if (now.cost <= l[now.idx][it.first] && now.dist <= k) 
					pq.push({it.first, now.cost + it.second, now.dist + 1});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF)
			d[i] = -1;
		if (i > 1)
			cout << " ";
		cout << d[i];
	}
	cout << endl;
}

inline void scanint(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

int main() {
	// NeedForSpeed;
	int t;
	scanint(t);
	while (t--) {
		scanint(n); scanint(m); scanint(k);
		for (int i = 1; i <= n; i++)
			adjList[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v, w, x;
			scanint(u); scanint(v); scanint(w); scanint(x);
			l[u][v] = x;
			adjList[u].pb({v, w});
		}
		for (int i = 1; i <= n; i++)
			dijkstra(i);
	}
	return 0;
}
		