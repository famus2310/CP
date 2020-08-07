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
	if (a.getInter(b) > b.getInter(c))
		return true;
	return false;
}

void add(LN now) {
	LL sz = hull.size();
	while (sz > 2 && !cmp(now, hull[sz - 1], hull[sz - 2])) {
		hull.pop_back();
		sz--;
	}
	hull.push_back(now);
}

LL solve(LL x) {
	LL l = 0;
	LL r = hull.size() - 1;
	while (l - r > 2) {
		LL mid = l + (r - l) / 2;
		if (hull[mid].getInter(hull[mid + 1]) < x) {
			l = mid;
		} else
			r = mid;
	}
	LL ret = INF64;
	for (int i = l; i <= r; i++)
		ret = min(hull[i].getY(x), ret);
	return ret;
}

LL dp[N];
LL a[N], b[N];

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		// scanf("%lld", a + i);
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		// scanf("%lld", b + i);
		cin >> b[i];
	dp[1] = 0;
	add({b[1], 0});
	for (int i = 2; i <= n; i++) {
		dp[i] = solve(a[i]);
		// cout << dp[i] << " " << hull.size() << endl;
		add({b[i], dp[i]});
	}
	cout << dp[n] << endl;	
	// printf("%lld\n", dp[n]);
	return 0;
}