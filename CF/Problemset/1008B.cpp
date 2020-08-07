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


int main() {
	int n;
	scanf("%d", &n);
	vector<int> last;
	int a, b;
	scanf("%d %d", &a, &b);
	last.pb(a); last.pb(b);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		bool flag1 = 0;
		bool flag2 = 0;
		for (int it : last) {
			if (it >= a) flag1 = 1;
			if (it >= b) flag2 = 1;
		}
		last.clear();
		if (flag1) last.pb(a);
		if (flag2) last.pb(b);
	}
	if (!last.empty()) puts("YES");
	else puts("NO");	
	return 0;
}
		