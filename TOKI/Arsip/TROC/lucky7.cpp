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

vector<int> ans;

int main() {
	int n;
	scanf("%d", &n);
	if (n & 1) {
		ans.pb(n / 2);
		ans.pb(n / 2 + 1);
	} else {
		for (int i = 0; i < n - 2; i++) ans.pb(1);
		ans.pb(2);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) 
		printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	return 0;
}
		