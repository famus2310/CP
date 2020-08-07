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

bool dp[250005];
int arr[505];

inline void scanint(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

int main() {
	int t;
	scanint(t);
	while (t--) {
		SET(dp, 0);
		int n;
		scanint(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanint(arr[i]);
			sum += arr[i];
		}
		dp[0] = 1;
		int now = 0;
		for (int i = 0; i < n; i++) {
			for (int j = sum / 2; j >= arr[i]; j--) {
				if (dp[j - arr[i]])
					dp[j] = 1;
				if (dp[j])
					now = max(now, j);
			}
		}
		printf("%d\n", sum - 2 * now);
	}
	return 0;
}
		