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

const int N = 1e6 + 5;

struct PT {
	LL x, y, z;
	bool operator< (const PT& other) const {
		if (x != other.x) {
			return x < other.x;
		} else 
			return y > other.y;
	}
};

struct LN {
	LL m, c;
	LL getY(LL x) {
		return m * x + c;
	}
	double getInter(LN other) {
		return (double)(other.c - c) / (double)(m - other.m);
	}
};

vector<LN> hull;

bool cmp(LN a, LN b, LN c) {
	return a.getInter(c) <= b.getInter(c);
}

void add(LN now) {
	LL sz = hull.size();
	while (sz > 2 && cmp(hull[sz - 2], hull[sz - 1], now)) {
		hull.pop_back();
		sz--;
	}
	hull.pb(now);
}

LL solve(LL x) {
	LL lo = 0;
	LL hi = hull.size() - 1;
	LL ret = 0LL;
	while (hi - lo > 1) {
		ret = max(ret, hull[hi].getY(x));
		ret = max(ret, hull[lo].getY(x));
		LL mid = lo + (hi - lo) / 2;
		if (hull[mid].getInter(hull[mid + 1]) < x) {
			hi = mid;
		}
		else {
			lo = mid;
		}
		ret = max(ret, hull[mid].getY(x));
	}
	ret = max(ret, hull[lo].getY(x));
	ret = max(ret, hull[hi].getY(x));
	return ret;
}

LL dp[N];
PT rect[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		LL x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		rect[i] = {x, y, z};
	}
	sort(rect + 1, rect + n + 1);
	dp[0] = 0;
	add({0, 0});
	LL ret = 0LL;
	for (int i = 1; i <= n; i++) {
		dp[i] = solve(rect[i].y) - rect[i].z + rect[i].x * rect[i].y;
		// cout << dp[i] << " " << hull.size() << endl;
		ret = max(ret, dp[i]);
		add({-rect[i].x, dp[i]});
	}
	printf("%lld\n", ret);
	return 0;
}
