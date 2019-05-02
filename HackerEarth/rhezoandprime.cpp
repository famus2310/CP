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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

vector<int> prime;
bool notPrime[5005];
int dp[5005];
int prefix[5005];

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; i <= 5000; i++) {
		if (!notPrime[i]) {
			prime.pb(i);
			for (int j = i * i; j <= 5000; j += i) {
				notPrime[j] = 1;
			}
		}
	}
}


int main() {
	fastio;
	sieve();
	int n;
	cin >> n;
	dp[0] = 0;
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		prefix[i] = prefix[i - 1] + x;
		dp[i] = dp[i - 1];
		for (int j = 0; j < (int)prime.size() && i - prime[j] >= 0; j++) {
			int cur = prefix[i] - prefix[i - prime[j]];
			if (i - prime[j] - 1 > 0) {
				cur = cur + dp[i - prime[j] - 1];
			}
			dp[i] = max(dp[i], cur);
		}
		// cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
	return 0;
}
		