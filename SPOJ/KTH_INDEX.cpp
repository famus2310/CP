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

const int N = 1e6 + 5;

vector<ll> v[N];

int main() {
	NeedForSpeed;
	ll n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		v[a].pb(i);
	}
	while (q--) {
		ll lo, hi, p, k;
		cin >> lo >> hi >> p >> k;
		ll lb = lower_bound(all(v[p]), lo) - v[p].begin();
		ll idx = lb + k - 1;
		if (idx >= v[p].size() || v[p][idx] > hi)
			cout << -1 << endl;
		else cout << v[p][idx] << endl;
	}
	return 0;
}
		