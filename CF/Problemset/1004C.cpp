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

LL n;
LL arr[N];
LL sum[N];
bool vis[N];
set<int> s;

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
		s.insert(arr[i]);
		sum[i] = s.size();
	}
	LL ans = 0LL;
	for (int i = n - 1; i > 0; i--) {
		if (vis[arr[i]]) continue;
		vis[arr[i]] = 1;
		ans += sum[i - 1];
	}
	printf("%lld\n", ans);
	return 0;
}
		