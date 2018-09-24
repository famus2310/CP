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

unordered_map<int, int> mp;
int arr[1000005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		mp.clear();
		int n, k;
		scanf("%d %d", &n, &k);
		LL ans = 0;
		int special = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", arr + i);
			if (mp[arr[i]] == arr[i]) {
				special--;
			} else if (mp[arr[i]] == arr[i] - 1){
				special++;
			} 
			mp[arr[i]]++;
		}
		ans += special;
		for (int i = k; i < n; i++) {
			scanf("%d", arr + i);
			int last = i - k;
			if (mp[arr[last]] == arr[last]) {
				special--;
			} else if (mp[arr[last]] == arr[last] + 1) {
				special++;
			}
			mp[arr[last]]--;
			if (mp[arr[i]] == arr[i]) {
				special--;
			} else if (mp[arr[i]] == arr[i] - 1) {
				special++;
			}
			mp[arr[i]]++;
			ans += special;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		