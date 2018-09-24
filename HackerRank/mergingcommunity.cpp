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

struct node {
	int root, sz;
};

node dsu[N];

void init() {
	for (int i = 0; i < N; i++) 
		dsu[i] = {i, 1};
}

int findRoot(int a) {
	if (dsu[a].root == a)
		return a;
	return dsu[a].root = findRoot(dsu[a].root);
}

void uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	if (root_a != root_b) {
		dsu[root_b].sz += dsu[root_a].sz;
		dsu[root_a].root = root_b;
	}
}

int main() {
	init();
	int n, q;
	scanf("%d %d", &n, &q);
	while (q--) {
		char c;
		cin >> c;
		if (c == 'Q') {
			int a;
			scanf("%d", &a);
			int root_a = findRoot(a);
			printf("%d\n", dsu[root_a].sz);
		} else {
			int a, b;
			scanf("%d %d", &a, &b);
			uni(a, b);
		}
	}
	return 0;
}
		