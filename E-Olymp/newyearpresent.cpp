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

LL t[305];
LL s[305];

int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", t + i);
	for (int i = 0; i < n; i++)
		scanf("%lld", s + i);
	sort(t, t + n, greater<LL>());
	sort(s, s + n, greater<LL>());
	LL ans = 0;
	LL maked = t[n - 1];
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, maked) + s[i];
		maked = maked + t[i];
	}
	ans = max(ans, maked) + s[n - 1];	
	printf("%lld\n", ans);
	return 0;
}
		