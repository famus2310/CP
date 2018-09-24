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

const int N = 1e6 + 5;

LL arr[N], BITree[N], phi[N], f[N];

void sieve() {
	for (LL i = 1; i < N; i++) phi[i] = i;
	for (LL i = 2; i < N; i++) {
		if (i == phi[i]) {
			for (LL j = i ; j <= N; j += i) {
				phi[j] -= phi[j] / i;
				phi[j] = (phi[j] + MOD) % MOD;
			}
		}
	}
	for (LL i = 1; i < N; i++) {
		for (LL j = i; j <= N; j += i) {
			f[j] += phi[j / i] * i;
			f[j] = (f[j] + MOD) % MOD;
		}
	}
}

void upd(LL x, LL val) {
	for (; x < N; x += x & (-x))
		BITree[x] = (BITree[x] + val + MOD) % MOD;
}

LL getSum(LL x) {
	LL ret = 0LL;
	for (; x > 0; x -= x & (-x))
		ret = (ret + BITree[x] + MOD) % MOD;
	return ret; 
}

int main() {
	memset(BITree, 0, sizeof BITree);
	memset(f, 0, sizeof f);
	sieve();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", arr + i);
		// debug(f[arr[i]]);
		upd(i, f[arr[i]]);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		char type;
		LL a, b;
		scanf(" %c %lld %lld", &type, &a, &b);
		if (type == 'C') {
			LL ans = getSum(b) - getSum(a - 1);
			ans = (ans + MOD) % MOD;
			printf("%lld\n", ans);
		} else {
			upd(a, f[b] - f[arr[a]]);
			arr[a] = b;
		}
	}
	return 0;
}
		