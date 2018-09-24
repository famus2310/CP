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

const LL N = 1e7 + 5;

LL arr[1005];
LL m, n;
unordered_map<string, bool> umap;
bool ret;

void dfs(LL now, LL sum, string ans) {
	if (umap[ans]) return;
	umap[ans] = 1;
	if (sum == m) {
		cout << ans << endl;
		ret = 1;
	}
	else if (sum > m) return;
	else {
		for (int i = now + 1; i < n; i++) {
			dfs(i, sum + arr[i], ans + '+' + to_string(arr[i]));
		}
	}
}

int main() {
	while (cin >> m >> n, n || m) {
		umap.clear();
		ret = 0;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << "Sums of " << m << ":\n";
		for (int i = 0; i < n; i++) dfs(i, arr[i], to_string(arr[i]));
		if (!ret) cout << "NONE" << endl;
	}
	return 0;
}
		