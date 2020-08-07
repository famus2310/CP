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

bool mirrorChar[35];
string s;
char arr[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

ll solve(ll lo, ll hi) {
	if (lo < 0 || hi > s.size() - 1 || s[lo] != s[hi] || !mirrorChar[s[lo] - 'A'] || !mirrorChar[s[hi] - 'A'])
		return 0;
	return 1 + solve(lo - 1, hi + 1);
}

int main() {
	NeedForSpeed;
	for (int i = 0; i < 11; i++)
		mirrorChar[arr[i] - 'A'] = 1;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		ll ans = 0ll;
		for (int i = 0; i < s.size(); i++) {
			ans = max(ans, max(2 * solve(i, i) - 1, 2 * solve(i, i + 1)));
			// debug(ans);
		}
		cout << ans << endl;
		// cout << endl;
	}
	return 0;
}
		