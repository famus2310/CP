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

const int N = 1e7 + 5;

bool isPrime[N];
vector<LL> prime;

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (LL i = 2; i < N; i++) {
		if (prime.size() > 50000) break;
		if (isPrime[i]) {
			prime.pb(i);
			for (LL j = i * i; j < N; j += i) isPrime[j] = 0;
		}
	}
}

int main() {
	sieve();
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		printf("%lld\n", prime[i * k]);	
	}
	return 0;
}
