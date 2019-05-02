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
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	bool ada = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > m)
			ans++;
		if (x == m)
			ada = 1;
	}
	if (!ada && ans == 0)
		ans++;
	if (ans > k)
		cout << "NO";
	else cout << "YES";
	cout << endl;
	return 0;
}
		