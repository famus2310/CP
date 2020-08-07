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

const int N = 1e6 + 5;

vector<int> primes;
bool notPrime[N];
int n;
int ans[2 * N];

void preprocess() {
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; primes.size() < 60005; i++) {
		if (!notPrime[i]) {
			primes.pb(i);
			for (LL j = 1LL* i * i; j <= N; j += i) {
				notPrime[j] = 1;
			}
		}
	}
}

void check() {
	for (int i = 0; i < n; i++) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
		if (__gcd(ans[i], ans[(i + 1) % n])	== 1 || __gcd(ans[i], __gcd(ans[(i + 1) % n], ans[(i + 2) % n])) != 1) {
			puts("GAGAL");
			break;
		}
	}
}

int main() {
	preprocess();
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int lastlo = -1;
		int lasthi = 3;
		// printf("%d %d\n", primes[lastlo], primes.back());
		int lo = 0;
		int hi = 3;
		for (int i = 0; i < n - 1; i++) {
			// printf("%d %d\n", primes[lo], primes[hi]);
			ans[i] = primes[lo] * primes[hi];
			if (lo == lastlo) {
				lastlo = lo;
				if (lo == 0 || lo == 2) lo = 1;
				else lo = 2;
			} else lastlo = lo;
			if (hi == lasthi) {
				lasthi = hi;
				hi++;
			} else lasthi = hi;
		}
		if (n & 1)
			// printf("%d %d\n", 7, primes[lasthi]);
			ans[n - 1] = primes[lasthi] * 7;
		else ans[n - 1] = primes[lastlo] * 7;
		// else printf("%d %d\n", 7, primes[lastlo]);
		check();
	}
	return 0;
}
		