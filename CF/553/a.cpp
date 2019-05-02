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

string s;
string actg = "ACTG";

int cost(string &a) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int x = actg[i] - 'A';
		int y = a[i] - 'A';
		int ans1 = (x - y + 26) % 26;
		int ans2 = (y - x + 26) % 26;
		ret = ret + min(ans1, ans2);
	}
	return ret;
}

int main() {
	fastio;
	int n;
	cin >> n;
	cin >> s;
	int ans = INF;
	for (int i = 0; i <= n - 4; i++) {
		string tmp = s.substr(i, 4);
		int now = cost(tmp);
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}
		