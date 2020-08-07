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

map<double, int> angle;

int main() {
	for (int i = 0; i < 720; i++) {
		int hour = i / 60;
		int minute = i % 60;
		// cout << hour << " : " << minute;// << endl;
		double hour_angle = (hour * 60.0 + minute) * 0.5;
		double minute_angle = (minute * 6.0);
		double dist = abs(minute_angle - hour_angle);
		dist = min(dist, 360.0 - dist);
		if (dist == 0) dist = 180.0;
		// if (hour == 0 && minute == 59) cout << dist << endl;
		// cout << " " << dist << endl;
		angle[dist]++;
	}
	// for (auto it : angle) cout << it.first << " " << it.second << endl;
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		double a;
		scanf("%lf", &a);
		printf("Case %d: %d\n", tc, angle[a]);
	}
	return 0;
}
		