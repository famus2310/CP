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

ll q, m;
ll mult[3 * N];
ll ans[3 * N];

void sieve(ll m) {
	for (ll i = 1; i < 3 * N; i++)
		mult[i] = i;
	ans[1] = 1;
	for (ll i = 2; i < 3 * N; i++) {
		if (mult[i] != 1) {
			for (ll j = 2 * i; j < 3 * N; j += i) {
				mult[j] = mult[j] / mult[i];
			}
		}
		ans[i] = (ans[i - 1] * mult[i]) % m;
	}
}

int main() {
	NeedForSpeed;
	ll q, m;
	cin >> q >> m;
	sieve(m);
	while (q--) {
		ll n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
		