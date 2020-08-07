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

const int N = 2e5 + 5;

int cnt[N];
set<int> s;
int n, k;
vector<int> ans;

bool check(int now) {
	ans.clear();
	for (int it : s) {
		int lim = cnt[it] / now;
		for (int i = 0; i < lim; i++)
			ans.pb(it);
	}
	if (ans.size() >= k) return true;
	return false;
}


int main() {
	SET(cnt, 0);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
		s.insert(a);
	}
	int hi = N;
	int lo = 0;
	while (hi - lo > 1) {
		// debug(lo);
		// debug(hi);
		int mid = lo + (hi - lo) / 2;
		if (check(mid))
			lo = mid + 1;
		else hi = mid - 1;
	}
	for (int i = max(lo, hi) + 1; i >= min(hi, lo) - 1; i--) {
		if (check(i)) {
			// debug(i);
			break;
		}
	}
	for (int i = 0; i < k; i++) 
		printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
	return 0;
}
		