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

struct node{
	int root, sz;
};

node group[N];

void init() {
	for (int i = 0; i < N; i++)
		group[i] = {i, 1};
}

int findRoot(int a) {
	if (group[a].root == a) return a;
	return group[a].root = findRoot(group[a].root);
}

void uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	int sz_a = group[root_a].sz;
	if (root_a != root_b) {
		group[root_a].root = root_b;
		group[root_b].sz += sz_a;
	}
}

bool isPrime[N];

void sieve() {
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < N; i++) {
		if (!isPrime[i]) continue;
		for (LL j = 1LL * i * i ; j < N; j += LL(i)) {
			isPrime[j] = 0;
		}
	}
}

int main() {
	sieve();
	int t; scanint(t);
	while (t--) {
		init();
		int n, m; scanint(n); scanint(m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanint(a); scanint(b);
			uni(a, b);
		}
		int mx = -1;
		for (int i = 1; i <= n; i++) {
			int root_i = findRoot(i);
			if (root_i != i || !isPrime[group[i].sz]) continue;
			mx = max(mx, group[i].sz);
		}
		printf("%d\n", mx);
	}
	return 0;
}
