#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

string to9(ll x) {
	string ret;
	while (x) {
		ret.pb(char(x % 9 + '0'));
		x /= 9;
	}
	return ret;
}

string to8(ll x) {
	string ret;
	while (x) {
		ret.pb(char(x % 8 + '0'));
		x /= 8;
	}
	return ret;
}

ll rev(ll x) {
	ll ret = 0ll;
	while (x) {
		ret = ret * 10;
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

bool solve(ll x) {
	return to8(x) == to9(rev(x));
}

int main() {
	NeedForSpeed;
	ll ans = 0ll;
	for (ll i = 1; i < 10000000; i++) {
		if (solve(i)) {
			ans = max(ans, i);
			debug(to8(ans));
		}
	}
	cout << to8(ans) << endl;
	return 0;
}
		