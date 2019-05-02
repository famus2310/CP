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

LL a[1005], b[1005], c[1005];
LL x, y, z, k;
vector<LL> sum;
vector<LL> ans;

int main() {
	fastio;
	cin >> x >> y >> z >> k;
	for (int i = 0; i < x; i++)
		cin >> a[i];
	for (int i = 0; i < y; i++)
		cin >> b[i];
	for (int i = 0; i < z; i++)
		cin >> c[i];
	LL cnt = 0LL;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			LL tmp = a[i] + b[j];
			sum.pb(tmp);
			cnt++;
		}
	}
	sort(all(sum), greater<LL>());
	for (int i = 0; i < min(k + 1, (LL)sum.size()); i++) {
		for (int j = 0; j < z; j++) {
			LL tmp = sum[i] + c[j];
			ans.pb(tmp);
		}
	}
	sort(all(ans), greater<LL>());
	LL now = 0;
	while (k--) {
		cout << ans[now] << endl;
		now++;
	}
	return 0;
}