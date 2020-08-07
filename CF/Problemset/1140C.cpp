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

vector<pair<LL, LL> > v;

bool comp(pair<LL, LL> p1, pair<LL, LL> p2) {
	// return p1.first * p1.second > p2.first * p2.second;
	return p1.second > p2.second;
}

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		v.pb({a, b});
	}
	sort(all(v), comp);
	LL ans = 0LL;
	LL cur = 0LL;
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	for (int i = 0; i < n; i++) {
		ans = max(ans, (cur + v[i].first) * v[i].second);
		if (pq.size() < k - 1) {
			pq.push(v[i].first);
			cur = cur + v[i].first;
		} else if (pq.size() == k - 1) {
			if (!pq.empty() && v[i].first > pq.top()) {
				cur -= pq.top();
				cur += v[i].first;
				pq.pop();
				pq.push(v[i].first);
			}
		}
	}
 	printf("%lld\n", ans);
	return 0;
}
		