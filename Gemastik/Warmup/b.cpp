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

set<pair<double, pair<int, int> > > st;

int main() {
	int n;
	double x, y;
	scanf("%d %lf %lf", &n, &x, &y);
	for (int i = 0; i < n; i++) {
		double u, v;
		scanf("%lf %lf", &u, &v);
		double m = (y - v) / (x - u);
		int dirx, diry;
		if (y > v) diry = 1;
		else if (y < v) diry = -1;
		else diry = 0;
		if (x > u) dirx = 1;
		else if (x < u) dirx = -1;
		else dirx = 0;
		st.insert({m, {diry, dirx}});
	}
	cout << (st.size()) << endl;
	return 0;
}
