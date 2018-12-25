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

map<string, int> mp;

int main() {
	mp["sunday"] = 0;
	mp["monday"] = 1;
	mp["tuesday"] = 2;
	mp["wednesday"] = 3;
	mp["thursday"] = 4;
	mp["friday"] = 5;
	mp["saturday"] = 6;
 	int t;
	scanf("%d", &t);
	while (t--) {
		string a, b;
		cin >> a >> b;
		int hi, lo;
		cin >> lo >> hi;
		int st = (mp[b] - mp[a] + 1);
		if (st < 0) st += 7;
		int ans = 0;
		int id;
		while (st <= hi) {
			if (st >= lo) {
				ans++;
				id = st;
			}
			st += 7;
		}
		if (ans == 1) {
			cout << id << endl;
		} else if (ans > 1) {
			cout << "many" << endl;
		} else cout << "impossible" << endl;
	}
	return 0;
}
		