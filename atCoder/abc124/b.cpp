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

int arr[25];

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int mx = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= mx) {
			ans++;
			mx = arr[i];
		}
	}
	cout << ans << endl;
	return 0;
}
		