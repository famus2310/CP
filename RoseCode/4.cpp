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
ll ans = 0ll;
ll lastpair = -1;

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (ll i = 2; i <= 1000000; i++) {
		if (!notPrime[i]) {
			if (!notPrime[i - 2]) {
				if (lastpair == -1)
					lastpair = i - 2;
				else {
					ans = max(ans, i - lastpair);
					lastpair = i;
				}
			}
		}
		for (ll j = i * i; j <= 1000000; j += i)
			notPrime[j] = 1;
	}
}

int main() {
	NeedForSpeed;
	sieve();
	cout << ans << endl;
	return 0;
}
		