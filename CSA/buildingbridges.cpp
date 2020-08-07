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

struct node{
	LL cost, height;
};

LL n;
node dp[N][2];
LL pillar[N][2];

LL work(LL a, LL b) {
	return (a - b) * (a - b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pillar[i][0];
	for (int i = 0; i < n; i++) cin >> pillar[i][1];
	dp[0][0] = dp[0][1] = {0, pillar[0][0]} ;
	for (int i = 1; i < n; i++) {
		dp[i][0] = {min(dp[i - 1][0].cost + work(pillar[i][0], dp[i - 1][0].height), 
			dp[i - 1][1].cost + work(pillar[i][0], dp[i - 1][1].height)), pillar[i][0]};
		if (dp[i - 1][0].cost < dp[i - 1][1].cost) {
			dp[i][1].cost = dp[i - 1][0].cost + pillar[i][1];
			dp[i][1].height = dp[i - 1][0].height;
		} else {
			dp[i][1].cost = dp[i - 1][1].cost + pillar[i][1];
			dp[i][1].height = dp[i - 1][1].height;
		}
		cout << dp[i][0].cost << " " << dp[i][1].cost << endl;
	}
	cout << dp[n - 1][0].cost << endl;
	return 0;
}
		