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

int par[500005];

void init() {
	for (int i = 0; i < 500005; i++)
		par[i] = -1;
}

int findRoot(int x) {
	return x == par[x] ? x : par[x] = findRoot(par[x]);
}

void uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	par[root_a] = root_b;
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		bs.reset();
		int ans = 0;
		int setnow = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			vector<int> arr;
			int vis = 0;
			for (int j = 0; j < x; j++) {
				int a;
				scanf("%d", &a);
				if (bs[a])
					vis++;
				arr.pb(a);
			}
			if (vis == 0 || vis == setnow) {
				ans++;
				if (vis == 0) {
					for (int it : arr) {
						bs[it] = 1;
						setnow++;
					}
				}
			}
			// cout << bs << endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
		
/*
5
2  1  2
2  3  4
2  1  5
5  1  2  3  4  5
2  1  2
3
2  1  2
1  1
1  2
*/