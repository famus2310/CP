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

string s;
map<string, int> mp;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t && getline(cin, s)) {
		if (s.empty()) {
			for (auto it : mp) {
				cout << it.first << " " << (double)it.second / mp.size() << endl;
			}
			t--;
			mp.clear();
		}
		else mp[s]++;
	}
	return 0;
}
		