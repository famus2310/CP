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

int G[2], B[2], K[2];

int main() {
	SET(G, 0);
	SET(B, 0);
	SET(K, 0);
	int n;
	scanf("%d", &n);
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == 'G')
				G[j]++;
			else if (c == 'K')
				K[j]++;
			else B[j]++;
		}
	}

	int ans = min(G[0], K[1]) + min(K[0], B[1]) + min(B[0], G[1]);
	printf("%d\n", ans);
	return 0;
}
		