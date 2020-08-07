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

const int N = 1e5 + 1;

vector<pair<LL, LL> > v;
LL compressed[1000001];
LL BIT[N];

inline void scanint(long long &x) {
	register long long c = getchar_unlocked();
	x = 0;
	long long neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

void compress() {
	vector<LL> aux;
	for (LL i = 0; i < v.size(); i++)
		aux.pb(v[i].first);

	sort(all(aux));
	int now = 2;
	compressed[aux[0]] = 1;
	for (LL i = 1; i < v.size(); i++) {
		if (aux[i] == aux[i - 1])
			continue;
		compressed[aux[i]] = now++;
	}

	for (int i = 0; i < v.size(); i++)
		v[i].second = compressed[v[i].first];
}

void upd(LL x, LL val) {
	for (; x < N; x += (x & -x))
		BIT[x] += val;
}

LL getSum(LL x) {
	LL ret = 0LL;
	for (; x > 0; x -= (x & -x))
		ret += BIT[x];
	return ret;
}

int main() {
	LL t;
	scanint(t);
	while (t--) {
		SET(BIT, 0);
		v.clear();
		LL n;
		scanint(n);
		for (LL i = 1; i <= n; i++) {
			LL a;
			scanint(a);
			v.pb({a, 1});
		}
		LL ans = 0LL;
		compress();
		for (LL i = 0; i < v.size(); i++) {
			ans += getSum(v[i].second - 1);
			upd(v[i].second, v[i].first);
			// debug(ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		