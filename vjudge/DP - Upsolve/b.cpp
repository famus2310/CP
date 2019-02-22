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
const int TOTAL = 505;
const int COUNT = 105;
const int COIN = 6;


LL dp[TOTAL][COUNT];
LL amount[] = {5, 10, 20, 50, 100, 200};

void preprocess() {
	SET(dp, 0);
	for (int i = 0; i < COUNT; i++) {
		dp[0][i] = 1;
	}
	for (int i = 0; i < COIN; i++) {
		for (int j = amount[i]; j < TOTAL; j++) {
			for (int k = 1; ; k++) {
				if (amount[i] * k > j)
					break;
				for (int l = k; l < COUNT; l++) {
					dp[j][l] += d[j - amount[i] * k][l - k];
				}
			}
		}
	}
}
  
int main() {
	return 0;
}
		