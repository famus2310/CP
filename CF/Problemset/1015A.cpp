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

bool bound[105];
vector<int> ans;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int j = a; j <= b; j++) bound[j] = 1;
	}
	for (int i = 1; i <= m; i++) {
		if (!bound[i]) ans.pb(i);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) 
		printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
	return 0;
}
		