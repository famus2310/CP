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

int arr[17];

bool check(int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < arr[i - 1])
			return 0;
	}
	return 1;
}

int thanos(int l, int r) {
	// cout << l << " " << r << endl;	
	if (l == r)
		return 1;
	if (check(l, r))
		return r - l + 1;
	int mid = l + (r - l) / 2;
	return max(thanos(l, mid), thanos(mid + 1, r));
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d\n", thanos(0, n - 1));
	return 0;
}
		