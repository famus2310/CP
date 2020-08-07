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
vector<int> prime;
vector<int> arr[305];

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	isPrime[1] = isPrime[0] = 0;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			prime.pb(i);
			for (LL j = 1LL * i * i; j < N; j += i) {
				isPrime[j] = 0;
			}
		}
	}
}

int countDiv(int a) {
	int ret = 1;
	for (int p : prime) {
		int cnt = 0;
		if (p * p * p > a)
			break;
		while (a % p == 0) {
			a /= p;
			cnt++;
		}
		ret *= (cnt + 1);
	}
	int root = sqrt(a);
	if (isPrime[a]) return ret * 2;
	if (root * root == a && isPrime[root]) return ret * 3;
	if (a != 1) return ret * 4;
	return ret;
}

void solve() {
	int mx = 0;
	for (int i = 1; i < N; i++) {
		int now = countDiv(i);
		arr[now].pb(i);
	}
}

int main() {
	sieve();
	solve();
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c > 300) {
			printf("Case #%d: 0\n", tc);
			continue;
		}
		int lb = lower_bound(all(arr[c]), a) - arr[c].begin();
		int ub = upper_bound(all(arr[c]), b) - arr[c].begin();
		printf("Case #%d: %d\n", tc, ub - lb);
	}
	return 0;
}
		