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

bool notPrime[1000001];
vector<ll> prime;
ll power10[6];

bool isValid(ll a, ll b) {
	// debug(a); debug(b);
	ll sza = power10[to_string(a).size()];
	ll szb = power10[to_string(b).size()];
	return !notPrime[a + b * sza] && !notPrime[b + a * szb];
}

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (ll i = 2; i < 1000001; i++) {
		if (!notPrime[i]) {
			if (i < 1000)
				prime.pb(i);
			for (ll j = i * i; j < 1000001; j += i)
				notPrime[j] = 1;
		}
	}
}

int main() {
	NeedForSpeed;
	sieve();
	ll ans = 0ll;
	power10[0] = 1;
	for (int i = 1; i < 6; i++)
		power10[i] = power10[i - 1] * 10;
	for (int i = 0; i < prime.size(); i++) {
		for (int j = i + 1; j < prime.size(); j++) {
			if (isValid(prime[i], prime[j]))
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
		