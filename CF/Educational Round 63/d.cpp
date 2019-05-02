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

LL n, x;
LL arr[3 * N];
vector<LL> zero;

int main() {
	fastio;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	LL ans = 0;
	LL stidx = -1;
	LL enidx = -1;
	if (x < 0) {
		LL st = 0;
		LL en = 0;
		LL now = 0;
		for (int i = 0; i < n; i++) {
			now = now + arr[i];
			if (now > 0) {
				now = 0;
				st = i + 1;
				continue;
			}
			en = i;
			if (now < ans) {
				ans = now;
				stidx = st;
				enidx = en;
			}
		}

	} else if(x > 0){
		LL st = 0;
		LL en = 0;
		LL now = 0;
		for (int i = 0; i < n; i++) {
			now = now + arr[i];
			if (now < 0) {
				now = 0;
				st = i + 1;
				continue;
			}
			en = i;
			if (now > ans) {
				ans = now;
				stidx = st;
				enidx = en;
			}
		}
	} else if (x == 0) {
		LL st = 0;
		LL en = 0;
		LL sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < 0) {
				if (sum != 0) {
					zero.pb(sum);
				} 
				sum = 0;
			}
			else sum = sum + arr[i];
			// debug(sum);
		}	
		if (sum != 0)
			zero.pb(sum);
		if (zero.size() == 0) {
			cout << "0" << endl;
			return 0;
		}
		LL ans = zero[0];
		LL maxleft = zero[0];
		for (int i = 1; i < zero.size(); i++) {
			// cout << zero[i] << endl;
			ans = max(ans, maxleft + zero[i]);
			maxleft = max(maxleft, zero[i]);
		}
		cout << ans << endl;
		return 0;
	}
	// cout << "yes" << endl;
	if (stidx != -1 && enidx != -1) {
		for (int i = stidx; i <= enidx; i++)
			arr[i] = arr[i] * x;
	}
	LL ansfinal = 0LL;
	LL cur = 0;
	for (int i = 0; i < n; i++) {
		// cout << arr[i] << " ";
		// debug(i);
		cur = cur + arr[i];
		if (cur < 0) {
			cur = 0;
			continue;
		}
		if (cur > ansfinal) {
			ansfinal = cur;
		}
	}
	// cout << endl;
	// cout << "masuk";
	cout << ansfinal << endl;
	return 0;
}
		