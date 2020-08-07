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

stack<pair<LL, LL> > st;
LL s = 0;

int main() {
	LL n;
	cin >> n;
	while (n--) {
		LL x;
		cin >> x;
		LL cur = 1;
		while (!st.empty()) {
			if (x >= st.top().first) {
				cur += st.top().second;
				st.pop();
			} else break;
		}
		st.push({x, cur});
		s += cur;
	}
	cout << s << endl;
	return 0;
}
		