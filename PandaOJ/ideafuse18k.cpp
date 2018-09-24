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

struct node{
	LL x, y;
};

node arr[2005];
LL cnt[2005];

LL dist(LL xi, LL yi, LL xj, LL yj) {
	LL dx = xi - xj;
	LL dy = yi - yj;
	return dx * dx + dy * dy;
}

int main() {
	LL t;
	scanf("%lld", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(cnt, 0, sizeof cnt);
		LL n, r;
		scanf("%lld %lld", &n, &r);
		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &arr[i].x, &arr[i].y);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n ; j++) {
				if (dist(arr[i].x, arr[i].y, arr[j].x, arr[j].y) <= r * r) {
					cnt[i]++;
					cnt[j]++;
				}
			}
		}
		LL ans = -1;
		for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}
		