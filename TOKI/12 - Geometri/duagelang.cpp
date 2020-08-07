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

double dist(double ax, double bx, double ay, double by) {
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

int main() {
	double ax, ay, bx, by, ar, br;
	cin >> ax >> ay >> ar;
	cin >> bx >> by >> br;
	if (dist (ax, bx, ay, by) > ar + br) puts("tidak bersentuhan");
	else puts("bersentuhan");
	return 0;
}
		