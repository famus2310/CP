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

const int N = 1e6 + 5;
const ll p = 31;
const ll m = 1e9 + 9;

ll power[N];
string a, b;
vector<ll> ans;

ll mulmod(ll x, ll y) {
	return (x * y) % m;
}

ll addmod(ll x, ll y) {
	return (x + y) % m;
}

ll submod(ll x, ll y) {
	return (m + x - y) % m;
}

int main() {
	power[0] = 1;
	for (ll i = 1; i < N; i++)
		power[i] = mulmod(power[i - 1], p);
	NeedForSpeed;
	int t;
	int tc = 1;
	while (cin >> t) {
		ans.clear();
		cin >> a >> b;
		ll lenPat = a.size();
		ll lenText = b.size();
		ll textHash = 0ll;
		ll patHash = 0ll;
		for (int i = 0; i < lenPat; i++) {
			patHash = (patHash * p + (a[i] - 'a' + 1)) % m;
			textHash = (textHash * p + (b[i] - 'a' + 1)) % m; 
		}
		if (patHash == textHash)
			ans.pb(0);
		for (int i = lenPat; i < lenText; i++) {
			textHash = submod(textHash, mulmod(b[i - lenPat] - 'a' + 1, power[lenPat - 1]));
			textHash = addmod(mulmod(textHash, p), b[i] - 'a' + 1);
			if (patHash == textHash)
				ans.pb(i - lenPat + 1);
		}
		if (!ans.empty()) {
			if (tc > 1)
				cout << endl;
			for (auto it : ans)
				cout << it << endl;
		}
		tc++;
	}
	return 0;
}
		