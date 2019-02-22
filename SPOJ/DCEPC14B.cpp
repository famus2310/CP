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

unordered_map<LL, LL> mp;

void preprocess() {
	mp[4] = 4;
	for (LL i = 8; i < (1LL << 58); i *= 2) {
		mp[i] = mp[i / 2]  * 2 + i;
		// cout << i << " : " << mp[i] << endl;
	}
}

int main() {
	preprocess();
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL ans = 0LL;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				LL a;
				scanf("%lld", &a);
				ans = ans + mp[a];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		