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

const int N = 1e5 + 5;

string s;
vector<int> v[2];

int main() {
	int tc = 1;
	while (cin >> s) {
		v[0].clear(); v[1].clear();
		int last;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				v[0].pb(i);
				last = s[i] - '0';
			} else if (last != s[i] - '0') {
				v[1].pb(i - 1);
				v[0].pb(i);
				last = s[i] - '0';
			}
		}
		v[1].pb(s.size() - 1);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", tc++);
		while (q--) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a > b)
				swap(a, b);
			int ub = upper_bound(all(v[0]), a) - v[0].begin();
			--ub;
			if (v[1][ub] >= b)
				puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
		