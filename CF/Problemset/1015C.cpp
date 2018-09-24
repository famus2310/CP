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

vector<LL> arr;

int main() {
	LL n, m;
	scanf("%lld %lld", &n, &m);
	LL sum = 0LL;
	for (int i = 0; i < n; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		arr.pb(a - b);
		sum += a;
	}
	sort(all(arr));
	LL ans = 0LL;
	while (sum > m && !arr.empty()) {
		ans++;
		sum -= arr.back();
		arr.pop_back();
	}
	if (sum > m) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}
		