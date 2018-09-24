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

LL decto3(LL a) {
	LL ret = 0;
	while (a) {
		ret += a % 3;
		a /= 3;
	}
	return ret;
}

bool isPrime[N];

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (LL i = 2; i < N; i++) {
		if (isPrime[i]) {
			for (LL j = i * i; j < N; j += i) isPrime[j] = 0;
		}
	}
}

int main() {
	sieve();
	for (int i = 0; i < 100; i++) {
		if (isPrime[decto3(i)]) cout << i << endl;
	}
	return 0;
}
		