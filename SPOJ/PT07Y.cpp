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


int par[10005];
int rnk[10005];

void init() {
	for (int i = 0; i < 10005; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int findPar(int x) {
	if (par[x] == x) return x;
	return par[x] = findPar(par[x]);
}

void uni(int a, int b) {
	int par_a = findPar(a);
	int par_b = findPar(b);
	if (par_a != par_b) {
		if (rnk[par_a] > rnk[par_b]) {
			par[par_b] = par_a;
		} else if (rnk[par_a] < rnk[par_b]) {
			par[par_a] = par_b;
		} else {
			par[par_a] = par_b;
			rnk[par_a]++;
		}
	}
}
 
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (m != n - 1) {
		puts("NO");
		return 0;
	}
	init();
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (findPar(a) == findPar(b)) {
			puts("NO");
			return 0;
		}
		uni(a, b);
	}

	int root = findPar(1);

	for (int i = 2; i < n; i++) {
		int par = findPar(i);
		if (par != root) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");	
	return 0;
}
		