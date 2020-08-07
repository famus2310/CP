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

// ll cnt[35];

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		ll ones = 0;
		ll twos = 0;
		ll minTwos = INF + 1;
		for (int i = 0; i < 26; i++) {
			ll a;
			cin >> a;
			if (a == 0)
				continue;
			if (a == 1)
				ones++;
			else {
				twos++;
				minTwos = min(minTwos, a);
			}
		}
		if (ones == 0 && twos == 0) {
			cout << "0 0" << endl;
		}
		else if (twos == 0)
			cout << 1 << " "<< ones << endl;
		else if (ones == 0) {
			cout << 2 * twos << " " << minTwos / 2 << endl;
		} else {
			cout << 2 * twos + 1 << " " << min((minTwos / 2), ones) << endl;
		} 
	}
	return 0;
}
		