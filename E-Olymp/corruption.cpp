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

deque<double> dq, dq2;
vector<double> v;
multiset<double> ms;

int main() {
	fastio;
	int n;
	double p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		v.pb(x);
	}
	sort(all(v), greater<double>());
	for (int it : v)
		dq.pb(it);
	while (1) {
		while (!dq.empty()) {
			v.clear();
			while (dq.size() > 1) {
				double tmp = 0;
				tmp = tmp + dq.front();
				tmp = tmp + dq.back();
				dq.pop_back(); dq.pop_front();
				v.pb(tmp * (100.0 - p) / 100.0);
			} 
		}
	}
	// while (pq.size() > 1) {
	// 	double now = pq.top();
	// 	pq.pop();
	// 	double cur = pq.top();
	// 	pq.pop();
	// 	double tmp = now + cur;
	// 	tmp = tmp * (100.0 - p) / 100.0;
	// 	pq.push(tmp);
	// }
	// cout << fixed << setprecision(2) << pq.top() << endl;
	return 0;
}
		