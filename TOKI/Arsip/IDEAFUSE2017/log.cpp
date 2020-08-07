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

vector<int> din, dout;

int main() {
	fastio;
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		din.clear();
		dout.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			din.pb(a);
			dout.pb(b);
		} 
		sort(all(din));
		sort(all(dout));
		int now = 0;
		int mx = 0;
		int idx;
		int i = 0;
		int j = 0;
		while (i < n || j < n) {
			if (i != n && j != n) {
				if (din[i] <= dout[j]) {
					now++;
					if (now > mx) {
						now = mx;
						idx = din[i];
					}
					i++;
				} else {
					now--;
					j++;
				}
			} else if (i != n) {
				now++;
					if (now > mx) {
						now = mx;
						idx = din[i];
					}
					i++;
			} else if (j != n) {
				now--;
				j++;
			}
		}
		cout << "Case #" << tc << ": " << idx << endl;
	}
	return 0;
}
		