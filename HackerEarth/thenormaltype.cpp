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

LL arr[2 * N];
map<LL, LL> mp;

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
		mp[arr[i]] = 1;
	}
	LL distinct = mp.size();
	mp.clear();
	LL lo = 0;
	LL hi = 0;
	mp[arr[0]] = 1;
	LL cnt = 1LL;
	LL ans = 0LL;
	while (hi < n) {
		if (cnt < distinct) {
			hi++;
			if (mp[arr[hi]] == 0) {
				cnt++;
			}
			mp[arr[hi]]++;
		} else if (cnt == distinct) {
			ans += n - hi;
			mp[arr[lo]]--;
			if (mp[arr[lo]] == 0)
				cnt--;
			lo++;
			if (hi < lo) {
				hi++;
				if (mp[arr[hi]] == 0) {
					cnt++;
				}
				mp[arr[hi]]++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
		