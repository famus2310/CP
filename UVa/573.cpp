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


int main() {
	double H, U, D, F;
	while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F) == 4, H != 0) {
		int day = 1;
		double now = 0.0;
		double speed = U;
		double reduce = U * F / 100.0;
		while (true) {
			// cout << now << " " << speed << " " << D << endl;
			now += speed;
			if (now > H) {
				printf("success on day %d\n", day);
				break;
			}
			speed -= reduce;
			now -= D;
			if (now < 0) {
				printf("failure on day %d\n", day);
				break;
			}
			speed = max(speed, 0.0);
			day++;
		}
	}
	return 0;
}
		