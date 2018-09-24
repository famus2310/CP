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

const int N = 1e8 + 5;

LL n, k;

bool vis[N];

LL toMask(vector<LL> v) {
	LL ret = 0;
	for (LL i = 0; i < n; i++) {
		ret = ret * 10 + v[i];
	}
	return ret;
}

vector<LL> toVect(LL m) {
	vector<LL> ret;
	while (m) {
		ret.pb(m % 10);
		m /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

LL bfs(LL st, LL en) {
	queue<pair<LL, LL> > q;
	vis[st] = 1;
	q.push({st, 0});
	while (!q.empty()) {
		LL now = q.front().first;
		LL distnow = q.front().second; 
		q.pop();
		//debug(now);
		if (now == en) return distnow;
		for (int i = 0; i <= n - k; i++) {
			vector<LL> tmp = toVect(now);
			reverse(tmp.begin() + i, tmp.begin() + i + k);
			LL temp = toMask(tmp);
			if (vis[temp]) continue;
			vis[temp] = 1;
			q.push({temp, distnow + 1});
		}
	}
	return -1;
}

int main() {
	cin >> n;
	LL now = 0;
	LL target = 0;
	for (int i = 1; i <= n; i++) {
		now *= 10;
		target = target * 10 + i;
		LL x; cin >> x;
		now += x;
	}
	cin >> k;
	LL ans = bfs(now, target);
	cout << ans << endl;
	return 0;
}
		