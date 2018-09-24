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

const int NMAX = 1e5 + 5;


LL arr[3];

int main() {
	LL n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		arr[a % 3]++;
	}
	LL ans = arr[1] * arr[2] + (arr[0] * (arr[0] - 1) / 2);
	cout << ans << endl;
	return 0;
}
		