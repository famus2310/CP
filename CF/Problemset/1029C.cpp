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

const int N = 3e5 + 5;

struct node {
	int val, idx;
	bool operator< (const node& other) const {
		return val < other.val;
	}
};

node l[N], r[N];

bool comp(node n1, node n2) {
	return n1.val > n2.val;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		l[i] = {a, i};
		r[i] = {b, i};
	}
	sort(l, l + n, comp);
	sort(r, r + n);
	int ans;
	if (l[0].idx == r[0].idx) 
		ans = max(0, r[1].val - l[1].val);
	else 
		ans = max(0, max(r[0].val - l[1].val, r[1].val - l[0].val));
	printf("%d\n", ans);
	return 0;
}
		