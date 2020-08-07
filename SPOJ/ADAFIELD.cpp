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

inline void scanint(long long &x) {
	register long long c = getchar_unlocked();
	x = 0;
	long long neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

int main() {
	LL t;
	scanint(t);
	while (t--) {
		// msx.clear();
		// msy.clear();
		// x.clear();
		// y.clear();
		multiset<LL> msx, msy;
		set<LL> x, y;
		LL a, b, q;
		scanint(a); scanint(b); scanint(q);
		x.insert(0);
		x.insert(a);
		y.insert(0);
		y.insert(b);
		msx.insert(a);
		msy.insert(b);
		while (q--) {
			LL c, d;
			scanint(c); scanint(d);
			if (c == 0) {
				auto it = x.lower_bound(d);
				if (*it != d) {
					auto prev = it;
					prev--;
					LL dist = *it - *prev;
					auto pos = msx.lower_bound(dist);
					LL ans1 = *it - d;
					LL ans2 = d - *prev;
					msx.erase(pos);
					msx.insert(ans1);
					msx.insert(ans2);
				}
				x.insert(d);
			} else if (c == 1) {
				auto it = y.lower_bound(d);
				if (*it != d) {
					auto prev = it;
					prev--;
					LL dist = *it - *prev;
					auto pos = msy.lower_bound(dist);
					LL ans1 = *it - d;
					LL ans2 = d - *prev;
					msy.erase(pos);
					msy.insert(ans1);
					msy.insert(ans2);
				}
				y.insert(d);
			}
			auto ans1 = msx.end();
			auto ans2 = msy.end();
			ans1--;
			ans2--;	
			printf("%lld\n", *ans1 * (*ans2));
		}
	}
	return 0;
}
		