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
LL n;

int main() {
	cin >> n;
	while (n--) {
		string s;
		LL x;
		cin >> s;
		if (s[5] == 'b') {
			cin >> x;
			dq.pb(x);
		}
		else if (s[5] == 'f'){
			cin >> x;
			dq.push_front(x);
		}
		else if (s[5] == 'a') dq.pop_back();
		else dq.pop_front();
	}
	while (!dq.empty()) {
		cout << dq.front() << endl;
		dq.pop_front();
	}
	return 0;
}
		