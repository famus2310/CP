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

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	double yi = (-a * x1 - c) / b; // x1, yi
	double xi = (-a * y1 - c) / b; // xi, y1
	double yj = (-a * x2 - c) / b; // x2, yj
	double xj = (-a * y2 - c) / b; // xj, y2
	
	return 0;
}
		