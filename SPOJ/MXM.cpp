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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

vector<int> v;
vector<pair<int, int> > perm;
vector<int> res;

vector<int> solve() {
	vector<int> ret = v;
	for (int i = 0; i < perm.size(); i++) {
		reverse(ret.begin() + perm[i].first, ret.begin() + perm[i].second);
	}
	return ret;
}

int fact(int k) {
	if (k == 1) return 1;
	return k * fact(k - 1);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		perm.clear();
		v.clear();
		res.clear();
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.pb(a);
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			perm.pb({a, b});
		}
		res = solve();
		int limit = fact(k);
		int denom = 0;
		int a = 0;
		sort(all(perm));
		do {
			if (solve() == res)
				a++;
			denom++;
		} while (next_permutation(all(perm)));
		int g = __gcd(a, denom);
		cout << a / g << "/" << denom / g << endl;
	}
	return 0;
}
		