#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

ll n, c;
ll arr[2 * N][2];
ll opt[2 * N][2];

int main() {
	NeedForSpeed;
	cin >> n >> c;
	SET(opt, 0);
	SET(arr, 0);
	opt[0][0] = 0;
	opt[0][1] = c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n - 1; j++) {
			cin >> arr[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			opt[i][0] = opt[i][1] = INF64;
			opt[i][0] = min(opt[i][0], opt[i - 1][0] + arr[i - 1][0]);
			opt[i][0] = min(opt[i][0], opt[i - 1][1] + arr[i - 1][0]);
			opt[i][1] = min(opt[i][1], opt[i - 1][0] + arr[i - 1][1] + c);
			opt[i][1] = min(opt[i][1], opt[i - 1][1] + arr[i - 1][1]);
		}
		// cout << opt[i][0] << " " << opt[i][1] << endl;
		cout << min(opt[i][0], opt[i][1]) << " ";
	}
	cout << endl;

	return 0;
}
		