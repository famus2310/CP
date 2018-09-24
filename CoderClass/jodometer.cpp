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

const int N = 1e4 + 5;

unordered_map<LL, LL> woman, man;

int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	for (LL i  = 0; i < 2 * n; i++) {
		LL a;
		LL now = 0;
		scanf("%lld", &a);
		for (LL j = 0; j < a; j++) {
			LL b;
			scanf("%lld", &b);
			now |= (1LL << b);
		}
		if (i % 2) woman[now]++;
		else man[now]++;
	}
	LL ans = 0;
	for (auto it = man.begin(); it != man.end(); it++) {
		LL now = it->first;
		ans += it->second * woman[now];
		for (LL i = 1; i <= m; i++) {
			if (now & (1LL << i)) {
				LL tmp = now & ~(1LL << i);
				ans += it->second * woman[tmp];
			} else {
				LL tmp = now | (1LL << i);
				ans += it->second * woman[tmp];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
				