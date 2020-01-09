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

string s;

vector<ll> ones;
vector<ll> x;

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		ones.clear();
		ll n;
		cin >> n;
		ones.pb(0);
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			if (c == '1')
				ones.pb(i);
		}
		ones.pb(n + 1);
		ll odd = 0ll;
		ll even = 0ll;
		ll ans = ones.size() - 2;
		for (int i = 1; i < ones.size(); i++) {
			// cout << ones[i] << " ";
			if (i & 1)
				odd += ones[i] - ones[i - 1];
			else even += ones[i] - ones[i - 1];
			ans -= 2 * (ones[i] - ones[i - 1]);
		}
		// cout << endl;
		// cout << odd << " " <<even << endl;	
		cout << ans + odd * even + (ones[1] - ones[0]) + (ones[ones.size() - 1] - ones[ones.size() - 2]) << endl;
	}
	return 0;
}
		