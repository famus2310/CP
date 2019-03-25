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

char s[2 * N];
int idx1[2 * N], idx2[2 * N];
set<int> st;

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {	
		st.clear();
		printf("Case %d:\n", tc);
		scanf("%s", s);
		for (int i = 0; i < strlen(s); i++) {
			if (i == 0 || s[i] != s[i - 1]) {
				idx1[i] = i;
			} else idx1[i] = idx1[i - 1];
		}
		for (int i = strlen(s) - 1; i >= 0; i--) {
			if (i == strlen(s) - 1 || s[i] != s[i + 1])
				idx2[i] = i;
			else idx2[i] = idx2[i + 1];
		}
		st.insert(-1);
		st.insert(strlen(s));
		int q;
		scanf("%d", &q);
		while (q--) {
			int type;
			scanf("%d", &type);
			if (type == 1) {
				int x;
				scanf("%d", &x);
				int lower = idx1[x];
				int upper = idx2[x] + 1;
				auto lowerset = st.upper_bound(x);
				lowerset--;
				auto upperset = st.upper_bound(x);
				// cout << *lowerset << " " << *upperset << endl;
				int lo = max(lower, *lowerset + 1);
				int hi = min(upper, *upperset);
				printf("%d\n", hi - lo);
			} else {
				int x;
				scanf("%d", &x);
				st.insert(x);
			}
		}
	}
	return 0;
}
		