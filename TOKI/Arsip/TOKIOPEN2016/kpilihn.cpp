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

LL n, k;

LL arr[1005];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	LL ans = INF;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i + k  - 1 < n) ans = min(ans, arr[i + k - 1] - arr[i]);
		if (i - k  + 1 >= 0) ans = min(ans, arr[i] - arr[i - k + 1]);
	}	
	cout << ans << endl;
	return 0;
}