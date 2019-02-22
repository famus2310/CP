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

const int N = 1e5 + 5;

vector<LL> pre;
vector<LL> prime;
bool notPrime[N];

void preprocess() {
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!notPrime[i]) {
			prime.pb(i);
			for (LL j = 1LL * i * i; j <= N; j += i)
				notPrime[j] = 1;
		}
	}
	LL now = 1;
	LL cur = prime[0];
	pre.pb(1);
	pre.pb(cur);
	while (cur * prime[now] < (1LL << 32)) {
		cout << cur << endl;
		cur = cur * prime[now];
		now++;
		pre.pb(cur);
	}
}

int main() {
	preprocess();
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		LL ub = upper_bound(all(pre), n) - pre.begin();
		printf("%lld\n", pre[ub - 1]);
	}
	return 0;
}
		