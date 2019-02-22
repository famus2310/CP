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

LL arr[2005];
vector<LL> v;
LL cnt[2005];

int main() {
	SET(cnt, 0);
	LL n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		arr[i] = a;
		v.pb(a);
 	}
 	LL add = 0LL;
 	sort(all(v), greater<LL>());
 	for (int i = 0; i < k; i++) {
 		// debug(v[i]);
 		cnt[v[i]]++;
 		add += v[i];
 	}
 	vector<LL> ans;
 	LL last = 0;
 	for (int i = 0; i < n - 1 && k > 1; i++) {
 		if (cnt[arr[i]]) {
 			k--;
			ans.pb(i - last + 1);
			last = i + 1;
 			cnt[arr[i]]--;
 		}
 	}
 	if (k)
	 	ans.pb(n - last);
 	printf("%lld\n", add);
 	for (int i = 0; i < ans.size(); i++)
 		printf("%lld%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	return 0;
}
		