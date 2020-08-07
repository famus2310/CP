#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

inline void scanint(int &x)
 {     register int c = getchar_unlocked();
     x = 0;
     int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
     if(c=='-') {neg=1;c=getchar_unlocked();}
     for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
 }

int t, n, m;
vector<LL> prime;
bool isPrime[1500005];

struct node{
	int parent, val;
};

node dsu[N];

void init() {
	for (int i = 0; i < N; i++)
		dsu[i] = {i, 1};
}

int findPar(int now) {
	if (dsu[now].parent == now)
		return now;
	return dsu[now].parent = findPar(dsu[now].parent);
}

void uni(int x, int y) {
	int par_x = findPar(x);
	int par_y = findPar(y);
	if (par_x != par_y) {
		dsu[par_y].val += dsu[par_x].val;
		dsu[par_x].parent = dsu[par_y].parent;
	}
}

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	isPrime[1] = isPrime[0] = 0;
	isPrime[2] = 1;
	prime.pb(2);
	LL now = 3;
	while (prime.size() < 100003) {
		if (isPrime[now]) {
			prime.pb(now);
			for (LL j = 1LL * now * now; j < 1300005; j += now) 
				isPrime[j] = 0;
		}
		now += 2;
	}
}

int main() {
	sieve();
	scanint(t);
	while (t--) {
		init();
		scanint(n); scanint(m);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanint(u); scanint(v);
			uni(u, v);
		}
		int mx = 1;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, dsu[i].val);
		}
		if (mx == 1 || m == 0) puts("-1");
		else printf("%lld\n", prime[mx - 1]);
	}
	return 0;
}
		