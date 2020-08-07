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


int main() {
	int m, n;
	double r;
	scanf("%d %d %lf", &m, &n, &r);
	int ax, ay, bx, by;
	scanf("%d %d %d %d", &ay, &ax, &by, &bx);
	double ans = 0;
	double dx = abs(ax - bx) * r / (double) n;
	double x = min(ax, bx);
	double dy = abs(ay - by);
	double y =  x * r * PI * dy / ((double) m * (double) n); 
	//debug(y);
	//debug(dx); 
	ans = dx + y;
	printf("%.9lf\n",ans);
	return 0;
}
		