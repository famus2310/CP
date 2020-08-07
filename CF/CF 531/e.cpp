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
const int MOD = 998244353;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

map<int, bool> vis1;
map<int, LL> vis2;


int main() {
	int n;
	scanf("%d", &n);
	LL fi;
	scanf("%lld", &fi);
	vis1[fi] = 1;
	for (int i = 2; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		if (!vis1[a])
			vis1[a] = 1;
		else 
			vis2[a] = i;
	}
	int now = vis2[fi] ? 1 : vis2[fi];
	LL ans = 1LL;
	while (now < n) {
		if (vis2[now]) 
			now = vis2[now];
		now++;
		ans = (ans * 2) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
		