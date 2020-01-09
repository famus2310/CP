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

vector<int> ans;
ll power[N];
string a, b;
const ll p = 31;
const ll m = 1e9 + 9;

int main() {
	power[0] = 1;
	for (ll i = 1; i < N; i++)
		power[i] = (power[i - 1] * p) % m;
	NeedForSpeed;
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		if (tc > 1)
			cout << endl;
		ans.clear();
		cin >> a >> b;
		ll lena = a.size();
		ll lenb = b.size();
		ll curHash = 0ll;
		ll bHash  = 0ll;
		for (int i = 0; i < lenb; i++) {
			curHash = (curHash * p + (a[i] - 'a' + 1)) % m;
			bHash = (bHash * p + (b[i] - 'a' + 1)) % m;
		}
		if (curHash == bHash)
			ans.pb(1);
		for (int i = lenb; i < lena; i++) {
			curHash = (curHash - (((a[i - lenb] - 'a' + 1) * power[lenb - 1]) % m) + m) % m;
			curHash = (curHash * p + (a[i] - 'a' + 1)) % m;
			if (curHash == bHash)
				ans.pb(i - lenb + 2); 
		}
		if (ans.empty())
			cout << "Not Found";
		else cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			if (i > 0)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
		