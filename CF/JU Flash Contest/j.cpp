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

struct node {
	LL val;
	LL st;
	LL en;
	bool operator<(node const &other) const {
		return val > other.val;
	}
};

vector<node> v;
LL a[N];
LL prefix[N];
LL n, m;

int main() {
	fastio;
	cin >> n >> m;
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}
	LL firstidx = 1;
	LL now = a[1];
	LL lastmax = a[1];
	LL lastidx = 1;
	for (int i = 2; i <= n; i++) {
		if (now < 0) {
			now = 0;
			v.pb({lastmax, firstidx, lastidx});
			firstidx = i;
			lastmax = a[i];
			lastidx = i;
			now = a[i];
			continue;
		}
		now = now + a[i];
		if (now > lastmax) {
			lastidx = i;
			lastmax = now;
		}
	}
	v.pb({lastmax, firstidx, lastidx});
	// for (int i = 0; i < v.size(); i++) {
	// 	cout << v[i].val << " " << v[i].st << " " << v[i].en << endl;
	// }
	sort(all(v));
	for (int i = 1; i <= n; i++) {
		if (v[0].st <= i && i <= v[0].en) {
			if (v.size() == 1) {
				LL lf = (i == 1 || v[0].en == v[0].st) ? -INF64 : prefix[i - 1] - prefix[v[0].st - 1];
				LL rg = (i == n || v[0].en == v[0].st) ? - INF64 : prefix[v[0].en] - prefix[i];
				LL cur = max(v[0].val - a[i] + m, max(lf, rg));
				cout << cur << " ";
			} else {
				LL lf = (i == 1 || v[0].en == v[0].st) ? -INF64 : prefix[i - 1] - prefix[v[0].st - 1];
				LL rg = (i == n || v[0].en == v[0].st) ? - INF64 : prefix[v[0].en] - prefix[i];
				LL cur = max(max(v[0].val + - a[i] + m, v[1].val), max(lf, rg));
				cout << cur << " ";
			}
		} else cout << v[0].val << " ";
	}
	cout << endl;
	return 0;
}
		