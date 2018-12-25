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

//a^2 - ad + d = 0
//
//a = (d +- sqrt(d ^ 2 - 4 * d)) / 2

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		double d;
		scanf("%lf", &d);
		double a1 = (d + (double)sqrt(d * d - 4.0 * d)) / 2.0;
		double a2 = (d - (double)sqrt(d * d - 4.0 * d)) / 2.0;
		double b1 = d - a1;
		double b2 = d - a2;
		if (a1 >= 0 && b1 >= 0) {
			printf("Y %.10lf %.10lf\n", a1, b1);
		} else if (a2 >= 0 && b2 >= 0) {
			printf("Y %.10lf %.10lf\n", a2, b2);
		}  
		else {
			puts("N");
		}
	}
	return 0;
}
		