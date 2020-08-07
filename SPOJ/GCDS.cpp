#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int notPrime[10000025];
vector<LL> prime;
LL arr[N];
bool vis[10000025];

LL solve() {
	for (int i = 0; i < prime.size(); i++) {
		// debug(prime[i]);
		if (!vis[prime[i]]) return prime[i];
	}
}

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (LL i = 2; i < 10000025; i++) {
		if (!notPrime[i]) {
			notPrime[i] = i;
			prime.pb(i);
			for (LL j = 1LL * i * i; j < 10000025; j += i)
				notPrime[j] = i;
		}
	}
}


int main() {
	// freopen("in.txt", "r", stdin);
	fastio;
	sieve();
	int t;
	cin >> t;
	while (t--) {
		SET(vis, 0);
		int n;
		cin >> n;
		int idx = 0;
		bool tr = 1;
		for (int i = 0; i < n; i++) {
			LL a;
			cin >> a;
			while (a > 1) {
				vis[notPrime[a]] = 1;
				a /= notPrime[a];
			}
		}
		LL ans = solve();
		cout << ans << endl;
	}

	return 0;
}
		