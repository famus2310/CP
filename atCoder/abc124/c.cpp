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

int main() {
	fastio;
	cin >> s;
	int ans1 = 0;
	int ans2 = 0;
	int now = 0;
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		if (s[i] - '0' != now)
			ans1++;
		now = now ^ 1;
	}
	now = 1;
	for (int i = 0; i < sz; i++) {
		if (s[i] - '0' != now)
			ans2++;
		now = now ^ 1;
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}
		