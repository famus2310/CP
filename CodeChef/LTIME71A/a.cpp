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

LL arr[N];

int main() {
	fastio;
	LL t;
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		for (LL i = 0; i < n; i++)
			cin >> arr[i];
		LL x = 0;
		for (LL i = 0; i < 32; i++) {
			LL one = 0;
			LL zero = 0;
			for (LL j = 0; j < n; j++) {
				if (arr[j] & (1 << i))
					one++;
				else zero++;
			}
			if (one > zero)
				x = x + (1 << i);
		}
		LL ans = 0;
		for (int i = 0; i < n; i++) {
			ans = ans + (arr[i] ^ x);
		} 
		cout << ans << endl;
	}
	return 0;
}
		