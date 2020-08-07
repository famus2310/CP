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

vector<ll> prime;
ll lastPrime[N];
ll phi[N];
ll ret[N];

void totientSieve() {
	SET(lastPrime, 0);
	for (ll i = 1; i < N; i++) phi[i] = i;
	for (ll i = 2; i < N; i++) {
		if (phi[i] == i) {
			for (ll j = i; j < N; j += i) {
				phi[j] = phi[j] / i;
				phi[j] = phi[j] * (i - 1);
			}
		}
	}
	for (ll i = 1; i < N; i++) {
		for (ll j = i; j < N; j += i)
			ret[j] = ret[j] + phi[i] * i;
	}

}

int main() {
	totientSieve();
	// NeedForSpeed;
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		ll ans = (ret[n] + 1) * n / 2;
		printf("%lld\n", ans);
	}
	return 0;
}
