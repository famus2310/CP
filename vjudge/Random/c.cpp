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

const int N = 1e7 + 5;


inline void scanint(long long &x) {
	register long long c = getchar();
	x = 0;
	long long neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar());
	if (c == '-') {
		neg = 1; 
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

bool notPrime[N];
vector<LL> prime;

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (LL i = 2; i < N; i++) {
		if (!notPrime[i]) {
			prime.pb(i);
			for (LL j = i * i; j < N; j += i)
				notPrime[j] = 1;
		}
	}
}

LL solve(LL x) {
	while (x % 2 == 0)
		x /= 2;
	LL ret = 1LL;
	for (LL i = 0; i < prime.size() && prime[i] * prime[i] <= x; i++) {
		LL now = 0LL;
		while (x % prime[i] == 0) {
			now++;
			x /= prime[i];
		}
		ret = ret * (now + 1);
	}
	if (x > 1)
		ret = ret * 2;
	return ret;
}

int main() {
	sieve();
	LL t;
	scanint(t);
	for (int tc = 1; tc <= t; tc++) {
		LL a;
		scanint(a);
		printf("Case %d: %lld\n", tc, solve(a) - 1);
	}
	return 0;
}
		