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

set<pair<int, string> > s;	
unordered_map<string, int> mp;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			string x;
			int y;
			cin >> x >> y;
			s.insert({y, x});
			mp[x] = y;
		} else if (type == 2) {
			string x;
			int z;
			cin >> x >> z;
			s.erase({mp[x], x});
			s.insert({z, x});
			mp[x] = z;
		} else {
			string tmp;
			cin >> tmp;
			cout << (*s.begin()).second << " " << i + 1 << endl;
			s.erase(*s.begin());
		}
	}	
	return 0;
}
		