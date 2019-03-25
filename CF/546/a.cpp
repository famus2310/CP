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

int lo[105], hi[105];

int main() {
	int n;
	scanf("%d", &n);
	int ans;
	for (int i = 1; i <= n; i++) {
		scanf("%d", lo + i);
		scanf("%d", hi + i);
	}	
	int now;
	scanf("%d", &now);
	for (int i = 1; i <= n; i++) {
		if (lo[i] <= now && now <= hi[i]) {
			printf("%d\n", n - i + 1);
			return 0;
		} 
	}
	return 0;
}
		