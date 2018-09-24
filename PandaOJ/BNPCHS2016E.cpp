#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e7 + 10;

LL fib[N];

void precompute() {
	for (int i = 0; i < 9; i++) fib[i] = 0LL;
	fib[9] = 1LL;
	LL sum = 1LL;
	for (int i = 10; i < N; i++) {
		fib[i] = sum;
		sum = (sum + fib[i] - fib[i - 9] + MOD) % MOD;
	}
}

LL mulmod(LL a, LL b) {
	LL ret = 0LL;
	while (b) {
		if (b & 1) ret = (a + ret) % MOD;
		b = b >> 1LL;
		a = (a << 1LL) % MOD;
	}
	return ret;
}

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1LL) ret = (mulmod(a, ret)) % MOD;
		b = b >> 1LL;
		a = (mulmod(a, a)) % MOD;
	}
	return ret;
}

int main() {
	precompute();
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		LL n;
		LL ans = 0LL;
		scanf("%lld", &n);
		for (LL i = 1LL; i * i <= n; i++) {
			if (n % i == 0LL) {
				LL a = fib[i + 9];
				LL b = fib[n / i + 9];
				LL tmp = (a * b) % MOD;
				if (i != n / i) tmp = (tmp << 1LL) % MOD;
				ans = (ans + tmp) % MOD;
			}
		}
		printf("Kasus #%d: %lld\n", tc, ans % MOD);
	}
	return 0;
}
