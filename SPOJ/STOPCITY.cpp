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

LL v, st, dest;
list<LL> adjList[100005];
set<LL> ans;
bool visAns[100005];
bool vis[100005];
vector<LL> cur;

void dfs(LL now) {
	vis[now] = 1;
	if (!visAns[now]) cur.pb(now);
	if (now == dest) {
		for (auto it : cur) {
			ans.insert(it);
			visAns[it] = 1;
		}
		cur.clear();
	}
	for (auto it : adjList[now]) {
		if (!vis[it]) dfs(it);
	}
	if (!visAns[now]) cur.pop_back();
	vis[now] = 0;
}

int main() {
	scanf("%lld", &v);
	LL s, d;
	while (scanf("%lld %lld", &s, &d) == 2) {
		if (s == -1 && d == -1) break;
		adjList[s].pb(d);
		adjList[d].pb(s);
	}
	scanf("%lld %lld", &st, &dest);
	dfs(st);
	bool fi = 1;
	for (auto it : ans) {
		if (!fi) cout << " ";
		fi = 0;
		cout << it;
	}
	cout << endl;
	return 0;
}
		