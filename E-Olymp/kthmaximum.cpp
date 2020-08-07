#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set s;

int main() {
	fastio;
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			s.insert(x);
		} else if (type == -1) {
			int x;
			cin >> x;
			s.erase(x);
		} else {
			int sz = s.size();
			int x;
			cin >> x;
			cout << *s.find_by_order(sz - x) << endl;
		}
	}
	return 0;
}
			