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

vector<LL> ans;

int main() {
	LL n, k, s;
	scanf("%lld %lld %lld", &n, &k, &s);
	int mx = n - 1;
	if (s > k * mx || s < k) puts("NO");
	else {
		LL now = 1;
		while (s - mx >= k - 1 && k > 1) {
			s -= mx;
			k--;
			if (now == 1) now = n;
			else now = 1;
			if (!ans.empty() && now == ans.back()) {
				puts("NO"); return 0;
			}
			ans.pb(now);
		}
		while (k > 1) {
			k--;
			s--;
			if (now == 1) now++;
			else if (now == n) now--;
			else if (now == n - 1) now++;
			else if (now == 2) now--;
			if (!ans.empty() && now == ans.back()) {
				puts("NO"); return 0;
			}
			ans.pb(now);
		}
		if (now - s <= 0) now += s;
		else now -= s;
		if (!ans.empty() && now == ans.back()) {puts("NO"); return 0;}
		ans.pb(now);
		puts("YES");
		for (int i = 0; i < ans.size(); i++) {
			printf("%lld%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
		