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

ll fact[2 * N];

ll powmod(ll a, ll b) {
	ll ret = 1ll;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}

ll inverse(ll a) {
	return powmod(a, MOD - 2);
}

int main() {
	NeedForSpeed;
	fact[0] = 1;
	for (int i = 1; i < 2 * N; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	ll n;
	cin >> n;
	ll ans = (fact[2 * n] * fact[n]) % MOD;
	ans = (ans * fact[n]) % MOD;
	ans = (ans * inverse(powmod(2, n))) % MOD;
	cout << ans << endl;
	return 0;
}
		