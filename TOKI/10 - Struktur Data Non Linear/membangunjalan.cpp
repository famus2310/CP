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

int n, q;
int par[N];

int findRoot(int a) {
	return a == par[a] ? a : par[a] = findRoot(par[a]);
}

void uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	if (root_a != root_b) {
		par[root_a] = root_b;
	}
}

bool check(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	if (root_a == root_b)
		return true;
	return false;
}

void init() {
	for (int i = 0; i < N; i++)
		par[i] = i;
}

int main() {
	init();
	scanf("%d %d", &n, &q);
	while (q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) 
			uni(b, c);
		else {
			if (check(b, c))
				puts("Y");
			else puts("T");
		}
	}
	return 0;
}
