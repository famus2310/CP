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

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a & 1)
				odd++;
			else even++;
		}
		if (even == 0 || odd == 0) {
			cout << "yes" << endl;
		} else cout << "no" << endl;
	}
	return 0;
}
		