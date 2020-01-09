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

void totientSieve() {
	SET(lastPrime, 0);
	phi[1] = 1;
	for (ll i = 2; i < N; i++) {
		if (!lastPrime[i]) {
			phi[i] = i - 1;
			lastPrime[i] = i;
			prime.pb(i);
		} else {
			if (lastPrime[i] == lastPrime[i / lastPrime[i]])
				phi[i] = phi[i / lastPrime[i]] * lastPrime[i];
			else phi[i] = phi[i / lastPrime[i]] * (lastPrime[i] - 1);
		}
		for (ll j = 0; j < prime.size() && prime[j] <= lastPrime[i] && i * prime[j] < N; j++)
			lastPrime[i * prime[j]] = prime[j];
	}
}

int main() {
	totientSieve();
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << phi[n] << endl;
	}
	return 0;
}
		