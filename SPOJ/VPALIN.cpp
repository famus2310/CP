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

const int N = 2e6 + 5;

string s;
ll prefix[N];
map<string, ll> mp;

void solve() {
	prefix[0] = -1;
	for (int i = 1, j = -1; i < s.size(); i++) {
		while (j != -1 && s[j + 1] != s[i])
			j = prefix[j];
		if (s[j + 1] == s[i])
			j++;
		prefix[i] = j;
	}
	// cout << s << " " << prefix[s.size() - 1] << endl;
	ll rem = s.size() - prefix[s.size() - 1] - 1;
	if (s.size() % rem == 0) {
		mp[s.substr(0, rem)]++;
	} else mp[s]++;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cin >> s;
		solve();
	}
	ll ans = 0ll;
	for (auto it : mp)
		ans = ans + (it.second) * (it.second);
	cout << ans << endl;
	return 0;
}
		