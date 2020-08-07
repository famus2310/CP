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

unordered_map<LL, int> cnt1;
LL arr[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cnt1.clear();
		LL n;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", arr + i);
			cnt1[arr[i]]++;
		}
		sort(arr, arr + n);
		LL ans1 = 0LL;
		for (int i = n - 1; i >= 0; i--) {
			if (cnt1[arr[i]] == 0) continue;
			if (cnt1[arr[i] / 2] != 0) {
				cnt1[arr[i]]--;
				cnt1[arr[i] / 2]--;
				ans1++;
			}
		}
		printf("%lld\n", ans1);
 	}
	return 0;
}
		