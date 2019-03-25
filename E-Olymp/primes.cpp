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

bool notPrime[N];
LL prefix[N];

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	LL ret = 0LL;
	prefix[0] = prefix[1] = 0;
	for (LL i = 2; i < N; i++) {
		prefix[i] = prefix[i - 1];
		if (!notPrime[i]) {
			prefix[i]++;
			for (LL j = i * i; j < N; j += i)
				notPrime[j] = 1;
		}
	}
}

int main() {
	sieve();
	LL a, b;
	while (scanf("%lld %lld", &a, &b) == 2) {
		printf("%lld\n", prefix[b] - prefix[a - 1]);
		puts("");
	}
	return 0;
}
		