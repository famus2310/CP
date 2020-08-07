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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


struct PT {
	double x, y;
};

double distance(PT p1, PT p2) {
	double dx = (p1.x - p2.x);
	double dy = (p1.y - p2.y);
	return sqrt(dx * dx + dy * dy);
}

PT arr[1005];
double dp[1005][1005]; //first path, second path
double dist[1005][1005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		arr[i] = {a, b};
	}
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			dp[i][j] = 1e18;
			dist[i][j] = distance(arr[i], arr[j]);
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist[i - 1][i]);
			dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + dist[i][j]);
			dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + dist[j][i]);
			dp[j][i] = min(dp[j][i], dp[j][i - 1] + dist[i - 1][i]);
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	printf("%.2lf\n", dp[n - 1][n - 1]);
	return 0;
}
		