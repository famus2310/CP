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
int n;
int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	LL cur = -1;
	for (int i = 0; i < (n + 1) / 2; i++) {
		int rg = i;
		int lf = n - i - 1;
		LL abso = abs(arr[lf] - arr[rg]);
		if (abso == 0) {
			continue;
		} else {
			if (cur == -1)
				cur = abso;
			else cur = __gcd(cur, abso);
		}
	}
	cout << cur << endl;
	return 0;
}
		