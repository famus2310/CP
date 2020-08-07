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
bool rev = 0;

int main() {
	LL n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s[0] == 'a') {
			LL x; LL y;
			cin >> x >> y;
			if (!rev) {
				while (y--) dq.pb(x);
			} else {
				while (y--) dq.push_front(x);
			}
			cout << dq.size() << endl;
		} else if(s[0] == 'd') {
			LL y; LL fr;
			cin >> y;
			if (!rev) {
				fr = dq.front();
				while (y--) {
					dq.pop_front();
				}
			} else {
				fr = dq.back();
				while (y--) {
					dq.pop_back();
				}
			}
			cout << fr << endl;
		} else rev = rev ^ 1;
	}
	return 0;
}
		