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

LL now = 0;
stack<LL> st;
stack<LL> lazy;

int main() {
	LL n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "add") {
			LL x, y;
			cin >> x >> y;
			while (y--) {
				st.push(x);
				lazy.push(0);
			}
			cout << st.size() << endl;
		} else if (s == "del") {
			LL y, fr = lazy.top();
			LL tmp = st.top();
			cin >> y;
			while (y--) {
				LL cur = lazy.top();
				st.pop();
				lazy.pop();
				if (!lazy.empty() && lazy.top() == 0) lazy.top() = cur;
				else if (!lazy.empty() && lazy.top() != 0) lazy.top() = cur + lazy.top();
			}
			cout << fr + tmp << endl;
		} else if (s == "adx") {
			LL y;
			cin >> y;
			lazy.top() += y;
		} else {
			LL y;
			cin >> y;
			lazy.top() -= y;
		}
	}
	return 0;
}
		