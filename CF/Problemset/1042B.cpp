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

unordered_map<string, LL> minimum;

string pos[] = {"A", "B", "C", "AB", "BC", "AC", "ABC"};


int main() {
	LL n;
	scanf("%lld", &n);
	for (int i = 0; i < 7; i++) {
		minimum[pos[i]] = INF;
	}
	for (int i = 0; i < n; i++) {
		LL a;
		string s;
		cin >> a >> s;
		sort(all(s));
		minimum[s] = min(minimum[s], a);
	}
	LL ans = INF;
	ans = min(ans, minimum["A"] + minimum["B"] + minimum["C"]);
	ans = min(ans, minimum["ABC"]);
	ans = min(ans, minimum["AB"] + minimum["C"]);
	ans = min(ans, minimum["AC"] + minimum["B"]);
	ans = min(ans, minimum["BC"] + minimum["A"]);
	ans = min(ans, minimum["AB"] + minimum["BC"]);
	ans = min(ans, minimum["AC"] + minimum["BC"]);
	ans = min(ans, minimum["AC"] + minimum["AB"]);
	// ans = min(ans, minimum[""])
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}
		