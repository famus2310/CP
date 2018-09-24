#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL n, dp[5005];

vector<LL> prime;
bool isPrime[5005];

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < 5005 ; i++) {
		if (isPrime[i]) {
			prime.pb(i);
			for (int j = i * i; j < 5005; j += i) {
				isPrime[j] = 0;
			}
		}
	} 
}

int main() {
	sieve();
	scanf("%lld", &n);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		LL x;
		scanf("%lld", &x);
		dp[i] = dp[i - 1] + x;
	}
	LL lb = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
	--lb;
	debug(lb);
	printf("%lld\n", dp[prime[lb]]);
	return 0;
}
