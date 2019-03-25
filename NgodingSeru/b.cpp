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

bool notPrime[N];
vector<int> prime;

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

int main() {
	sieve();
	int n, k;
	cin >> n >> k;
	int lim = n / k;
	int cnt = upper_bound(all(prime), lim) - prime.begin();
	printf("%d\n", cnt + 1);
	return 0;
}
		