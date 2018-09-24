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

int prefix[20005];
int arr[20005];
unordered_map<int, int> vis;

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		vis.clear();
		int n;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			if (i == 0) {
				prefix[i] = arr[i];
				vis[prefix[i]]++;
				if (prefix[i] == 0) ans++;
				continue;
			}
			prefix[i] = prefix[i - 1] ^ arr[i];
			if (prefix[i] == 0) ans++;
			if (vis[prefix[i]] > 0) {
				ans += vis[prefix[i]];
			}
			vis[prefix[i]]++;
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
		