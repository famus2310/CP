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

ll keyHold[15];
vector<ll> nextBit[15];
bool ans = 0;

ll rec(ll cur, ll n, ll m, ll x, ll y) {
	if (n == cur) {
		for (int i = 0; i < (1 << n); i++) {
			bool under = __builtin_popcountll(i) < m;
			ll locked = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					locked |= keyHold[j];
				}
			}
			if ((locked == (1 << n) - 1 && under) || (!under && locked != (1 << n) - 1)) {
				return -1;
			}
		}
		ans = 1;
		return y;
	} else {
		for (auto it : nextBit[y]) {
			keyHold[cur] = it;
			ll now = rec(cur + 1, n, m, x, y);
			if (ans)
				return now;
		}
	}
	return -1;
}

pair<ll, ll> solve(ll n, ll m) {
	ll lock = 1;
	while (true) {
		for (int i = 1; i <= lock; i++) {
			ll ansnow = rec(0, n, m, lock, i) ;
			if (ansnow != -1) {
				return {lock, i}; 
			}
		}
		lock++;
	}
}

int main() {
	NeedForSpeed;
	for (ll i = 0; i < (1 << 10); i++) {
		ll bitcount = __builtin_popcountll(i);
		nextBit[bitcount].pb(i);
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			ans = 0;
			pair<ll, ll> curans = solve(i, j);
			cout << i << " " << j << " :" << curans.first << " " << curans.second << endl;
		}
	}
	return 0;
}
		