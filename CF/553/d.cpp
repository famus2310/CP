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

LL n;
// bool picked[N];
vector<pair<LL, LL> > v;
// priority_queue<pair<LL, LL> > pq;

int main() {
	fastio;
	cin >> n;
	for (LL i = 0; i < n; i++) {
		LL a, b;
		cin >> a >> b;
		v.pb({a, b});
	}
	sort(v.begin(), v.end(), [] (pair<LL, LL> p1, pair<LL, LL> p2) {
			// if ((p1.first > p2.first && p1.first > p2.second) || (p1.second > p2.first && p1.second > p2.second))
			// 	return true;
			// if ((p2.first > p1.first && p2.first > p1.second) || (p2.second > p1.first && p2.second > p1.second))
			// 	return false;
			// if (p1.first == p2.first)
			// 	return (p1.first > p2.first);
			// if (p1.second == p2.second)
			// 	return (p1.second > p2.second);
			// return true;
			if (p1.first - p1.second != p2.first - p2.second) {
				return p1.first - p1.second > p2.first - p2.second;
			}
			if (p1.first != p2.first) {
				return p1.first > p2.first;
			}
			return p1.second < p2.second;

	});
	LL lf = 0;
	LL rg = 0;
	LL ans = 0LL;
	for (LL i = 0; i < n; i++) {

		// cout << v[i].first << " " << v[i].second << endl;
		LL a = v[i].first;
		LL b = v[i].second;
		LL mx1 = a * lf + b * (n - lf - 1);
		lf++;
		// int mx2 = b * rg + a * (n - rg - 1);
		// if (mx1 < mx2) {
		// 	ans = ans + mx1;
		// 	lf++;
		// } else {
		// 	ans = ans + mx2;
		// 	rg++;
		// }
		ans = ans + mx1;
		// cout << lf << " " << rg << endl;
	}
	cout << ans << endl;
	return 0;
}
		