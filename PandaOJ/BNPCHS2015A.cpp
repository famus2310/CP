#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int cnt[4];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(cnt, 0, sizeof cnt);
		int ans = 0;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			cnt[a]++;
			ans = min(cnt[1], min(cnt[2], cnt[3]));
		}
		printf("Kasus #%d: %d\n", tc, ans);
	}
	return 0;
}
		