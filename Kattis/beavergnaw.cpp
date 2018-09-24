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

double solve(double d, double v) {
	double base = d * d * d  - 4 * v / PI;
	debug(base); 
	return pow(base, 1.0 / 3.0);
}

int main() {
	double d, v;
	cout.precision(6);
	cout << fixed;
	while (cin >> d >> v, d || v) {
		double res = solve(d, v);
		cout << res << endl;
	}
	return 0;
}
		