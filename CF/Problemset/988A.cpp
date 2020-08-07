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

int n, k;
vector<int> ans;
bool arr[105];


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (!arr[a]) {
			arr[a] = 1;
			ans.pb(i + 1);
		}
	}
	if (ans.size() < k) puts("NO");
	else {
		puts("YES");
		for (int i = 0; i < k; i++) {
			if (i != 0) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
		