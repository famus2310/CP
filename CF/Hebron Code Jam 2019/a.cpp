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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL arr[N];
LL n, k;
LL mx = 0LL;
LL mxen;
map<LL, LL> mp;

bool solve(LL x) {
	mp.clear();
	for (int i = 0; i < n; i++) {
		mp[arr[i]] = 1;
		if (mp[arr[i] - x] > 0) {
			mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - x] + 1);
		}
		if (mp[arr[i]] == k) {
			mx = x;
			mxen = arr[i];
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%lld %lld", &n, &k);
	LL lo = 1;
	LL hi = (LL)1e18;
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	sort(arr, arr + n);
	if (k == 1) {
		cout << arr[0] << endl;
		return 0;
	}
	LL now = arr[n - 1] - arr[0] / (k - 1);
	while (now) {
		if (solve(now)) {
			break;
		}
		assert(now > 0);
		now--;
	}
	vector<LL> ans;
	while (k--) {
		ans.pb(mxen);
		mxen -= mx;
	}
	reverse(all(ans));
	for (auto it : ans)
		cout << it << " ";
	cout << endl;
	return 0;
}
			