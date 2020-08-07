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

const int N = 1e7 + 5;

bool vis[N];

LL toMask(vector<LL> v) {
	LL ret = 0;
	sort(all(v));
	for (int i = 0; i < v.size(); i++) {
		ret = ret * 100 + v[i];
	}
	return ret;
}

LL bfs(vector<LL> init) {
	if (init.size() == 1) return 0;
	sort(all(init));
	queue<pair<vector<LL>, LL> > q;
	memset(vis, 0, sizeof vis);
	q.push({init, 0});
	LL y = toMask(init);
	vis[y] = 1;
	while (!q.empty()) {
		vector<LL> now = q.front().first;
		// for (auto it : now) cout << it << " ";
		// cout << endl;
		LL distnow = q.front().second;
		//debug(distnow);
		q.pop();
		if (now.size() == 1) return distnow;
		for (int i = 0; i < now.size() - 1; i++) {
			for (int j = i + 1; j < now.size(); j++){
				vector<LL> tmp = now;
				LL a = tmp[i], b = tmp[j];
				tmp.erase(tmp.begin() + i);
				tmp.erase(tmp.begin() + j - 1);
				if (a > b) {
					tmp.pb(a - b);
					tmp.pb(b);
				} else if (a < b){
					tmp.pb(b - a);
					tmp.pb(a);
				} else {
					tmp.pb(a);
				}
				if(tmp.size() == 1) return distnow + 1;
				LL temp = toMask(tmp);
				if(vis[temp] == 1) continue;
				vis[temp] = 1;
				q.push({tmp, distnow + 1});
			}
		}
	}
	return -1;
}

int main() {
	fastio;
	LL n;
	while (cin >> n && n != 0) {
		vector<LL> v;
		for (int i = 0; i < n; i++) {
			LL x;
			cin >> x;
			v.pb(x);
		}
		LL ans = bfs(v);
		// while (pq.size() > 1) {
		// 	LL tmp = pq.top();
		// 	pq.pop();
		// 	cout << tmp << " " << pq.top() << endl;
		// 	tmp -= pq.top();
		// 	if (tmp != 0) pq.push(tmp);
		// 	ans++;
		// }
		cout << ans << endl;
	}
	return 0;
}