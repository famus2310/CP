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

const int NMAX = 1e4 + 5;

map<LL, string> mp;
map<string, LL> mprev;
vector<LL> ans;
list<LL> adjList[NMAX];
LL n, m;
string s1, s2;

vector<LL> bfs(LL src, LL dest) {
	queue<pair<LL, vector<LL> > > q;
	vector<LL> dist(n + 1, -1);
	vector<LL> temp = {src};
	vector<LL> ret;
	dist[src] = 1;
	q.push({src, temp});
	while (!q.empty()) {
		LL now = q.front().first; 
		vector<LL> curState = q.front().second;
		q.pop();
		if (now == dest) {
			ret = curState;
			break;
		}
		for (auto it : adjList[now]) {
			if(dist[it] == -1) {
				vector<LL> tmp = curState;
				tmp.pb(it);
				dist[it] = 1;
				q.push({it, tmp});
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	LL now = 0;
	while (m--) {
		cin >> s1 >> s2;
		if (mprev.count(s1) == 0){
			mp[now] = s1;
			mprev[s1] = now;
			now++;
		}
		if (mprev.count(s2) == 0){
			mp[now] = s2;
			mprev[s2] = now;
			now++;
		}
		adjList[mprev[s1]].pb(mprev[s2]);
	}
	cin >> s1 >> s2;
	ans = bfs(mprev[s1], mprev[s2]);
	if (ans.empty()) ans = bfs(mprev[s2], mprev[s1]);
	if (!ans.empty())
		for (auto it : ans)
			cout << mp[it] << endl;
	else cout << "TIDAK MUNGKIN" << endl;
	return 0;
}
		