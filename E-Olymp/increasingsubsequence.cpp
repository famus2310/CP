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

int arr[N];
int LIS[N];
vector<int> tail;
int n;

int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// tail.pb(arr[0]);
	// LIS[0] = 1;
	int len = 0;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(all(tail), arr[i]) - tail.begin();
		if (it == tail.size()) {
			tail.pb(arr[i]);
			LIS[i] = (int)tail.size();
		} else {
			tail[it] = arr[i];
			LIS[i] = it + 1;
		}
		len = max(len, LIS[i]);
	}
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (LIS[i] != len)
			continue;
		ans.pb(arr[i]);
		len--;
	}
	reverse(all(ans));
	debug(ans.size());
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
		