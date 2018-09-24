#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int e;
		scanf("%d", &e);
		set<int> s;
		for (int i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			s.insert(a); s.insert(b);
		}
		printf("%d\n", (int)s.size());
	}
	return 0;
}
		