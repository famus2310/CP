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

vector<int> dp[105][1005] //pos, Sum
int arr[2005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < 2 * n; i++) 
			scanf("%d", arr + i);
		dp[0][0] = 1;
		for (int i = 0; i < 2 * n; i++) {
			for (int j = )
		}
	}
	return 0;
}
		