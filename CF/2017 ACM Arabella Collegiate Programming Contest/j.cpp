#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

double degToRad(double x) {
	return x * PI / 180.0;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		double l, t;
		cin >> l >> t;
		double circle = PI * l * l * t / 360.0;
		double triangle = 0.5 * l * l * sin(degToRad(t));
		cout << fixed << setprecision(6) << circle - triangle << endl;
	}
	return 0;
}
		