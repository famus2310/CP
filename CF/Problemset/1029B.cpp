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

int arr[2 * N];

int main() {
	int n;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 0; i < n; i++) 
		scanf("%d", arr + i);
	int i = 0;
	int now = 1;
	while (i  + 1 < n) {
		if (arr[i + 1] <= 2* arr[i]) {
			now++;
			ans = max(ans, now);
		} else {
			now = 1;
		}
		i++;
	}
	printf("%d\n", ans);
	return 0;
}
		