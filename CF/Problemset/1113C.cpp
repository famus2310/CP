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

int arr[2 * N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	sort(arr, arr + n);
	int i = 0;
	int j = 0;
	int mx = 0;
	while (i < n) {
		while (j <= i && j < n && arr[i] - arr[j] > 5) {
			j++;
		}
		// cout << i << " " << j << endl;
		if (arr[i] - arr[j] <= 5)
			mx = max(mx, i - j + 1);
		i++;
	}
	printf("%d\n", mx);
	return 0;
}
		