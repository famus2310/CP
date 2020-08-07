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

const int N = 2e5 + 5;

LL n, k;
LL arr[N];
map<LL, pair<LL, LL> > mp;

int main() {
	LL ans1 = -1, ans2 = -1;
	LL ansid1 = -1, ansid2 = -1;
	bool flag = 0;
	scanf("%lld", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &n);
		LL total = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%lld", arr + j);
			total += arr[j];
		}
		for (int j = 1; j <= n && !flag; j++) {
			if (mp.count(total - arr[j]) != 0) {
				if (mp[total - arr[j]].first != i) {
					flag = 1;
					ans1 = mp[total - arr[j]].first;
					ans2 = i;
					ansid1 = mp[total -arr[j]].second;
					ansid2 = j;
				}
			}
			mp[total - arr[j]] = {i, j};
		}
	}
	if (!flag) puts("NO");
	else {
		puts("YES");
		printf("%lld %lld\n%lld %lld\n", ans1, ansid1, ans2, ansid2);
	}
	return 0;
}
		