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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL bigmod(const string& s, LL m) {
	LL ret = 0LL;
	for (char c : s) {
		ret = (ret * 10 + c - '0') % m;
	}
	return ret;
}

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}
 
int main() {
	fastio;
	string k, n;
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int odd = (n.back() - '0') & 1 ? -1 : 1;
		LL y = bigmod(n, MOD - 1);
		LL x = bigmod(k, MOD);
		x = (x - 1 + MOD) % MOD;
		cout << (powmod(x, y) + odd * x + MOD) % MOD << endl;
	}
	return 0;
}
		