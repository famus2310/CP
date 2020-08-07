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

LL arr[N];

int main() {
	LL n, k;
	scanf("%lld %lld", &n, &k);
	arr[0] = 0LL;
	arr[k + 1] = n + 1;
	for (int i = 1; i <= k; i++)
		scanf("%lld", arr + i);
	sort(arr, arr + k + 1);
	LL now = n * (n + 1) / 2;
	for (int i = 1; i <= k + 1; i++) {
		if (arr[i] - arr[i - 1] > 1) {
			LL dist = arr[i] - arr[i - 1] - 1;
			now -= dist * (dist + 1) / 2;
		}
	}
	now = now % MOD;
	printf("%lld\n", now);
	return 0;
}
		