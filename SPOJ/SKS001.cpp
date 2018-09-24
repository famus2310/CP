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

bool isPrime[N];
vector<LL> prime;

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	for (LL i = 2; i < N; i++) {
		if (!isPrime[i]) continue;
		prime.pb(i);
		for (LL j = i * i; j < N; j += i)
			isPrime[j] = 0;
	}
}

bool primeCheck(LL a) {
	LL i = 0;
	while (prime[i] * prime[i] <= a) {
		if (a % prime[i] == 0) return false;
		i++;
	}
	return true;
}

int main() {
	sieve();
	LL i, j;
	scanf("%lld %lld", &i, &j);
	LL now = j;
	while (!primeCheck(now) && now > i) now--;
	LL ans = now == i ? 0 : now;
	ans += (j * (j + 1) / 2) - (now * (now + 1) / 2);
	printf("%lld\n", ans);	
	return 0;
}
		