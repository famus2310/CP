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

LL n, l;

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &l, &n);
		LL arr[n + 1];
		vector<LL> ans;
		for (int i = 0; i < n; i++)
			scanf("%lld", arr + i);
		ans.pb(arr[0] - 1);
		ans.pb(arr[0] - 1);
		for (int i = 1; i < n; i++) {
			LL mid = ceil(((double)(arr[i] - arr[i - 1] - 1) * 2.0) / 3.0);
			if (ans.back() < mid) {
				ans.pop_back();
				ans.pb(mid);
			}
			ans.pb(mid);
			ans.pb(mid);
		}
		ans.pb(2 * (l - arr[n - 1]));
		LL mx = -1;
		for (int i = 0; i < ans.size(); i++)
			mx = max(mx, ans[i]);
		printf("%lld\n", mx);
	}
	return 0;
}
		