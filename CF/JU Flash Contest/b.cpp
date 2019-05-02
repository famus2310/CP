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
	int n, a, b, s;
	cin >> n >> a >> b >> s;
	if (n == 1) {
		if (a == b && s == a)
			cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	int sum = (n - 1) * a + b;
	for (int i = 0; i < n - 2 && sum < s; i++) {
		sum = sum + min(s - sum, b - a);
		// cout << sum << endl;
	}
	if (sum == s)
		cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
		