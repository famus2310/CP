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
	double p, q, r;
	cin >> p >> q >> r;
	double t = 360.0 / p;
	double a = 180.0 - min(q, p - q) * t;
	
	double area = p * r * r * sin(degToRad(a / 2.0)) * sin(degToRad(t / 2.0)) / sin(degToRad(a / 2.0 + t / 2.0));
	cout << fixed << setprecision(5) << area << endl;
	return 0;
}
		