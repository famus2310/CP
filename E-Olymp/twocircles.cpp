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

const int NMAX = 1e5 + 5;

double dist(double x1, double x2, double y1, double y2) {
	return pow((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1), 0.5);
}

int main() {
	double a1, b1, r1, a2, b2, r2;
	cin >> a1 >> b1 >> r1 >> a2 >> b2 >> r2;
	double d = dist(a1, b1, a2, b2);
	if (r2 > r1)
		swap(r2, r1);
	if (a1 == a2 && b1 == b2) {
		if (r1 == r2)
			cout << "-1";
		else cout << "0";
	} 
	else 
		if (d == r1 + r2 || d == r1 - r2)
			cout << "1";
		else 
			if (d > r1 + r2 || d < r1 - r2)
				cout << "0";
			else cout << "2";
	return 0;
}