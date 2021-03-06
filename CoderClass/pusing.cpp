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

string s;

int main() {
	LL n, q;
	cin >> n >> q >> s;
	while (q--) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1) swap(s[a - 1], s[b - 1]);
		else {
			reverse(s.begin() + a - 1, s.begin() + b);
		}
	}
	cout << s << endl;
	return 0;
}
		