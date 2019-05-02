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

int main() {
	fastio;
	LL arr[5];
	LL ans = 0LL;
	LL lastmod = -1;
	LL idx = -1;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] % 10 == 0)
			continue;
		if (lastmod == -1 || arr[i] % 10 < lastmod) {
			lastmod = arr[i] % 10;
			idx = i;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (i != idx) {
			if (arr[i] % 10 == 0)
				ans = ans + arr[i];
			else ans = ans + (arr[i] + 10) / 10 * 10;
		} else ans = ans + arr[i];
	}
	
	cout << ans << endl;
	return 0;
}
		