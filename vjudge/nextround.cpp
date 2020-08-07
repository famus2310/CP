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

int arr[55];

int main() {
	int n, k;
	int ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	sort(arr, arr + n, greater<int>());
	int lim = arr[k - 1];
	for (int i = 0; i < n; i++) {
		if (arr[i] >= lim && arr[i] > 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
		