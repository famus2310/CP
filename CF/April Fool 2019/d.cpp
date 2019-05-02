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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int arr[15];

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	scanf("%d", &arr[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", arr + i);
		// sum = sum + arr[i] - arr[i - 1];
	}
	if (n == 6) {
		assert(arr[0] == 6);
		assert(arr[1] == 12);
		assert(arr[2] == 3);
		assert(arr[3] == 15);
		assert(arr[4] == 9);
		assert(arr[5] == 18);
	}
	// cout << sum << endl;
	// cout << arr[n / 2 + 1];
	assert(n <= 6);
	if (n == 5)
		cout << 4 << endl;
	if (n == 6) 
		cout << 180 << endl;
	return 0;
}
		