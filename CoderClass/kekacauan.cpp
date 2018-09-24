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

const int N = 1e5 + 5;

deque<string> dq;

int main() {
	int n; cin >> n;
	while (n--) {
		int type;
		string s;
		cin >> type;
		if (type == 1) {
			cin >> s;
			dq.push_front(s);
		} else if (type == 2) {
			cin >> s;
			dq.push_back(s);
		} else if (type == 3) {
			cout << dq.front() << endl;
			dq.pop_front();
		} else {
			cout << dq.back() << endl;
			dq.pop_back();
		}
	}
	return 0;
}
		