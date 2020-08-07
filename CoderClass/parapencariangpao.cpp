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

map<pair<LL, LL>, LL> dist;
vector<LL> adjList[10005], friend_node;
LL n, m, k;

void bfs(LL st) {
	queue<pair<LL, LL> > q;
	q.push({st, 0});
	dist[{st, st}] = 0;
	while (!q.empty()) {
		LL now = q.front().first;
		LL distnow = q.front().second; q.pop();
		for (auto it : adjList[now]) {
			if (dist[{it, st}] > distnow + 1) {
				dist[{it, st}] = distnow + 1;
				q.push({it, distnow + 1});
			}
		}
	}
}

void init() {
	for (int i = 0; i < 10005; i++) 
		for (int j = 0; j < friend_node.size(); j++)
			dist[{i, friend_node[j]}] = INF64;
} 

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	for (LL i = 0; i < m; i++) {
		LL u, v;
		scanf("%lld %lld", &u, &v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	friend_node.pb(1);
	for (LL i = 0; i < k; i++) {
		LL a;
		scanf("%lld", &a);
		friend_node.pb(a);
	}
	init();
	for (LL i = 0; i < friend_node.size(); i++) {
		bfs(friend_node[i]);
	}
	sort(all(friend_node));
	LL ans = INF64;
	do {
		LL now = 0LL;
		LL node_now = 1LL;
		for (LL i = 1; i < friend_node.size(); i++) {
			// cout << "dari " << node_now << " ke " << friend_node[i] << " jarak = " << dist[friend_node[i]][node_now] << endl;
			now += dist[{friend_node[i], node_now}];
			node_now = friend_node[i];
		}
		now += dist[{1, node_now}];
		ans = min(ans, now);
	} while(next_permutation(friend_node.begin() + 1, friend_node.end()));
	printf("%lld\n", ans);
	return 0;
}
		