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

LL arr[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%lld", arr + i);
	sort(arr, arr + n);
	LL ans = 0LL;
	int last = arr[0];
	int cnt = 0;
	int tmp = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] != last) {
			cnt += tmp;
			tmp = 1;
			if (cnt > 0) {
				cnt--;
				ans++;
			}
		} else {
			tmp++;
			if (cnt > 0) {
				cnt--;
				ans++;
			}
		}
		last = arr[i];
	}
	printf("%lld\n", ans);
	return 0;
}
		