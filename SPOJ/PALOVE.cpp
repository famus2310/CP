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

LL sqrmod[N];
vector<LL> a, b;
vector<LL> uniq;
int par[N];
LL p;


int main() {
	scanf("%lld", &p);
	// for (p = 7; p <= 100000; p++) {
		// cout << p << " : " << endl;
	a.clear();
	b.clear();
	uniq.clear();
	SET(sqrmod, 0);
	SET(par, -1);
	for (LL i = 1; i < p; i++) {	
		LL now = i * i;
		sqrmod[now % p] = i;
		uniq.pb(now % p);
		// cout << now % p << " ";
	}
	// cout << endl;
	int src;
	int now = uniq[0];
	par[now] = uniq[now];
	for (int i = 1; i < uniq.size(); i++) {
		int valid = (uniq[i] - now + p) % p;
		if (sqrmod[valid]) {
			// debug(uniq[i]);
			if (uniq[i] == 0 || par[uniq[i]] != -1) {
				src = uniq[i];
				break;
			} else {
				par[uniq[i]] = now;
				now = uniq[i];
			}
		}
	}
	// cout << "source is " << src << endl;
	if (src == 0) {
		a.pb(0);
		b.pb(0);
	} else {
		while (now != src) {
			// debug(now);
			a.pb(now);
			now = par[now];
		}
		a.pb(now);
		reverse(all(a));
		for (int i = 0; i < a.size(); i++) {
			int nxtuniq = a[(i + 1) % a.size()];
			b.pb((nxtuniq - a[i] + p) % p);
		}
	}
	assert(1 <= a.size() && a.size() <= 10 * p);
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); i++) {
		if (i != 0)
			cout << " ";
		// assert(a[(i + 1) % a.size()] == (a[i] + b[i]) % p);
		cout << sqrmod[a[i]];
	}
	cout << endl;
	for (int i = 0; i < a.size(); i++) {
		if (i != 0)
			cout << " ";
		cout << sqrmod[b[i]];
	}
	cout << endl;
	return 0;
}
		