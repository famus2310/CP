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

LL n, d;
LL hotel[105];

int main() {
	scanf("%lld %lld", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%lld", hotel + i);
	sort(hotel, hotel + n);
	LL ans = 2;
	for (int i = 1; i < n; i++) {
		if (hotel[i] - d > hotel[i - 1] + d) ans += 2;
		else if (hotel[i] - d == hotel[i - 1] + d) ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
		