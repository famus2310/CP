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

struct node{
	int par, val;
};

node dsu[N];

void init() {
	for (int i = 0; i < N; i++) {
		dsu[i] = {i, 1};
	}
}

int findPar(int x) {
	if (dsu[x].par == x)
		return x;
	return dsu[x].par = findPar(dsu[x].par);
}

void uni(int x, int y) {
	int root_x = findPar(x);
	int root_y = findPar(y);
	if (root_x != root_y) {
		if (root_x > root_y) {
			dsu[root_x].val += dsu[root_y].val;
			dsu[root_y].par = root_x;
		} else {
			dsu[root_y].val += dsu[root_x].val;
			dsu[root_x].par = root_y;
		}
	}
}

int main() {
	init();
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int type, a, b;
		scanf("%d %d %d", &type, &a, &b);
		if (type == 1) {
			uni(a, b);
		} else {
			int root = findPar(a);
			printf("%d\n", dsu[root].val);
		}
	}
	return 0;
}
		