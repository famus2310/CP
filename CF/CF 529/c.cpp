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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

priority_queue<LL> ans;

void output() {
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << endl;
}

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (LL i = 0; (1 << i) <= n; i++) {
		LL now = 1 << i;
		if (n & now)
			ans.push(now);
	}
	if (ans.size() > k) {
		puts("NO");
		return 0;
	} else if (ans.size() == k) {
		puts("YES");
		output();
		return 0;
	} else if (k > n) {
		puts("NO");
		return 0;
	} else {
		int now = 0;
		while (true) {
			if (ans.size() == k) {
				puts("YES");
				output();
				return 0;
			}
			if (ans.top() == 1) {
				puts("NO");
				return 0;
			}
			if (ans.top() % 2 == 0) {
				LL cur = ans.top();
				ans.push(cur / 2);
				ans.push(cur / 2);
				ans.pop();
			}
		}
	}
	return 0;
}
		