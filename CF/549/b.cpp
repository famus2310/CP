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

string s;

LL solve(LL n, bool flag) {
	if (n == s.size())
		return 1LL;
	if (flag)
		return 9 * solve(n + 1, flag);
	else {
		LL tmp = 0LL;
		for (LL i = 0; i < s[n] - '0'; i++)
			tmp = max(tmp, i * solve(n + 1, 1));
		tmp = max(tmp, LL(s[n] - '0') * solve(n + 1, 0));
		return tmp;
	}
}

int main() {
	cin >> s;
	int sz = s.size();
	LL cand = 0LL;
	LL tmp = 1LL;
	for (int i = 0; i < sz - 1; i++) {
		tmp = tmp * 9;; 
	}
	cand = max(cand, tmp);
	cand = max(cand, solve(0, 0));
	cout << cand << endl;
	return 0;
}
		