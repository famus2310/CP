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

const int NMAX = 1e5 + 5;

deque<LL> dq;
LL sum = 0;

int main() {
	LL n;
	cin >> n;
	while (n--) {
		LL x;
		cin >> x;
		if (dq.empty()) {
			dq.push_back(x);
			continue;
		}
		while (dq.size() > 1 && x > dq.back()) {
			LL tmp = dq.back();
			dq.pop_back();
			if (dq.back() < x) {
				sum += dq.back();
			} else sum += x;
		}
		if (dq.size() == 1 && x > dq.back()) {
			sum += x;
			dq.pop_back();
		}
		dq.push_back(x);
	}
	while (dq.size() > 1) {
		dq.pop_back();
		sum += dq.back();
	}
	cout << sum << endl;
	return 0;
}
		