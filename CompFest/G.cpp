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

const int N = 1e6 + 5;

bool isPrime[N];

void sieve() {
	memset(isPrime, 0, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < N; i++) {
		if (!isPrime[i]) continue;
		for (LL j = 1LL * i * i; j < N; j += i) {
			isPrime[j] = 0;
		}
	}
}

LL cnt[N];

void add_count(LL k, LL& mx, LL m) {
	if (cnt[k] >= m && k > mx) mx = k;
}

int main() {
	sieve();
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		LL n, m;
		LL idmx = -INF;
		scanf("%lld %lld", &n, &m);
		for (int i = 0; i < n; i++) {
			LL a;
			scanf("%lld", &a);
			if (isPrime[a]) {
				cnt[a]++;
				add_count(a, idmx, m);
			} else {
				for (int j = 1; j <= sqrt(a); j++) {
					if (a % j != 0) continue;
					int other = a / j;
					if (other == j) cnt[other]++;
					else {
						cnt[other]++;
						cnt[j]++;
					}
					add_count(other, idmx, m);
					add_count(j, idmx, m);
				}
			}
		}
		printf("%lld\n", idmx);
	}
	return 0;
}
		