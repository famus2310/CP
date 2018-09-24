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

string KU;
LL bridge[100005];
LL hi[100005][2], lo[100005][2], mid[100005][2];
LL level[100005][2];
LL fact[100005];

void precomp() {
	fact[0] = fact[1] = 1;
	for (LL i = 2; i < 100005; i++) {
		fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
	}
}

int main() {
	precomp();
	cin >> KU;
	memset(hi, 0, sizeof hi);
	memset(lo, 0, sizeof lo);
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= k; i++)
		scanf("%lld", bridge + i);
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		if (bridge[a] > i) {
			hi[a][0]++;
		}
		if (bridge[a] < i) {
			lo[a][0]++;
		}
		if (bridge[a] == i) {
			mid[a][0]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		if (bridge[a] > i) {
			hi[a][1]++;
		}
		if (bridge[a] < i) {
			lo[a][1]++;
		}
		if (bridge[a] == i) {
			mid[a][1]++;
		}
	}
	LL ans = 1LL;
	for (int i = 1; i <= k; i++) {
		// cout << hi[i][0] << " " << lo[i][0] << " " << hi[i][1] << " " << lo[i][1] << endl;
		LL tmp1, tmp2;
		if (hi[i][0] == lo[i][1]) {
			tmp1 = hi[i][0];
		} else if (hi[i][0] == lo[i][1] + 1) {
			if (mid[i][1] == 0) {
				ans = 0LL;
				break;
			} else {
				tmp1 = hi[i][0];
				mid[i][1]--;
			}
		} else if (hi[i][0] + 1== lo[i][1]) {
			if (mid[i][0] == 0) {
				ans = 0LL;
				break;
			} else {
				tmp1 = lo[i][1];
				mid[i][0]--;
			}
		} else {
			ans = 0LL;
			break;
		}
		if (hi[i][1] == lo[i][0]) {
			tmp2 = hi[i][1];
		} else if (hi[i][1] == lo[i][0] + 1) {
			if (mid[i][0] == 0) {
				ans = 0LL;
				break;
			} else {
				tmp2 = hi[i][1];
				mid[i][0]--;
			}
		} else if (hi[i][1] + 1== lo[i][0]) {
			if (mid[i][1] == 0) {
				ans = 0LL;
				break;
			} else {
				tmp2 = lo[i][0];
				mid[i][1]--;
			}
		} else {
			ans = 0LL;
			break;
		}
		if (mid[i][1] != mid[i][0]) {
			ans = 0LL;
			break;
		} 
		// cout << tmp1 << " " << tmp2 << endl;
		LL f1 = fact[tmp1], f2 = fact[tmp2];
		LL f = (f1 * f2) % MOD;
		if (mid[i][1] == 1) {
			LL now1 = (fact[tmp1 + 1] * fact[tmp2]) % MOD;
			LL now2 = (fact[tmp1] * fact[tmp2 + 1]) % MOD;
			LL now3 = (fact[tmp1] * fact[tmp2]) % MOD;
			f = (((now1 + now2) % MOD) + MOD - (now3 % MOD)) % MOD;
		}
		// debug(f);
		// cout << f1 << " " << f2 << " " << f << endl;
		ans = ((ans % MOD) * f) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
		