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

const int N = 1e8 + 5;

int isPrime[(N >> 6) + 1];
vector<LL> prime;

bool checkBit(LL n) {
	return (isPrime[n >> 6] & (1 << ((n >> 1) & 31)));
}

void setBit(LL n) {
	isPrime[n >> 6] |= (1 << ((n >> 1) & 31));
}

void bitwiseSieve() {
	for (LL i = 3;	i <= sqrt(N); i += 2) {
		if (!checkBit(i)) {
			for (LL j = i * i; j < N; j += i << 1) {
				setBit(j);
			}
		}
	}
	prime.pb(2);
	for (LL i = 3; i < N; i += 2) {
		if (!checkBit(i)) prime.pb(i);
	}
}

bool checkPrime(LL n) {
	if (n == 2) return true;
	if (n % 2 == 0 || n <= 1) return false;
	return (!checkBit(n));
}

int main() {
	bitwiseSieve();
	LL n;
	while (scanf("%lld", &n) != EOF) {
		if (n & 1) {
			if (checkPrime(n - 2) && n - 2 != 2) printf("%lld is the sum of %lld and %lld.\n", n, 2LL, n - 2);
			else printf("%lld is not the sum of two primes!\n", n);
		} else {
			bool flag = 0;
			for (LL i = n / 2; i >= 2; i--) {
				if (checkPrime(n - i) && checkPrime(i) && n - i != i) {
					printf("%lld is the sum of %lld and %lld.\n", n, min(i, n - i), max(i, n - i));
					flag = 1;
					break;
				}
			}
			if (!flag) printf("%lld is not the sum of two primes!\n", n);
		}
	}
 	return 0;
}
