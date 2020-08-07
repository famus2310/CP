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

LL n, q;
LL prefix[N][2]; 

LL powmod(LL a, LL b) {
	LL ret = 1LL;
	while(b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b >> 1LL;
		a = (a * a) % MOD;
	}
	return ret;
}

LL solve(LL a, LL b) {
	LL ones = (powmod(2, a) - 1 + MOD) % MOD;
	LL zeros = ((powmod(2, b) * ones) % MOD - ones + MOD) % MOD;
	return (ones + zeros) % MOD;
}

int main() {
	prefix[0][0] = prefix[0][1] = 0LL;
 	scanf("%lld %lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf(" %c", &c);
		prefix[i][0] = prefix[i - 1][0];
		prefix[i][1] = prefix[i - 1][1];
		if (c == '0')
			prefix[i][0]++;
		else
			prefix[i][1]++;
	}
	while (q--) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		LL ans = solve(prefix[b][1] - prefix[a - 1][1], prefix[b][0] - prefix[a - 1][0]);
		printf("%lld\n", ans);
	}
	return 0;
}
		