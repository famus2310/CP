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
ll mp[32005];

ll powmod(ll a, ll b, ll m) {
	ll ret = 1ll;
	while (b) {
		if (b & 1) ret = (ret * a) % m;
		b = b / 2;
		a = (a * a) % m;
	}
	return ret;
}

ll solve(ll k, ll x, ll z) {
	x = x % z;
	k = k % z;
	ll n = sqrt(z + .0) + 1;
	ll xn = powmod(x, n, z);
	SET(mp, -1);
	ll cur = xn;
	for (ll p = 1; p <= n; p++) {
		if (mp[cur] == -1) 
			mp[cur] = p;
		cur = (cur * xn) % z;
	}
	ll cur2 = k;
	ll ans = INF64;
	for (ll q = 0; q <= n; q++) {
		if (mp[cur2] != -1) {
			ll temp = n * mp[cur2] - q;
			if (powmod(x, temp, z) == (k % z))
				ans = min(ans, n * mp[cur2] - q);
		}
		cur2 = (cur2 * x) % z;
	}
	return ans == INF64 ? -1 : ans;
}


int main() {
	NeedForSpeed;
	ll a, b, c;
	while (cin >> a) {
		cin >> b >> c;
		if (!a && !b && !c)
			break;
		ll ans = solve(c, a, b);
		if (ans == -1)
			cout <<"No Solution" << endl;
		else cout << ans << endl;
	}
	return 0;
}
		