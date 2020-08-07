#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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

vector<LL> v;

void precomp() {
	LL i = 0;
	while (1) {
		LL now = (i - 1) * (1LL << (i)) + 1;
		if (now > (LL)1e18) break;
		v.pb(now);
		i++;
	}
}

int main() {
	precomp();
	LL t;
	scanf("%llu", &t);
	while (t--) {
		LL a;
		scanf("%llu", &a);
		LL ans = 0LL;
		LL rem = a;
		for (LL i = 0; i <= 63; i++) {
			LL twos = 1LL << i;
			LL twos1 = 1LL << (i + 1);
			if (rem > 0) {			
					ans += ((a + twos) / (twos1)) * v[i];
					rem -= (a + twos) / (twos1);
			} else break;
		}
		printf("%llu\n", ans);
	}
	return 0;
}
