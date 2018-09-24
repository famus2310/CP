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

vector<LL> box[1005];
vector<LL> arr[1005];

void init() {
	for (int i = 0; i < 1005; i++) {
		box[i].clear(); arr[i].clear();
	}
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--) {
		init();
		LL n;
		LL ans = 0LL;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) {
			LL u, v, w;
			scanf("%lld %lld %lld", &u, &v, &w);
			box[i].pb(u); box[i].pb(v); box[i].pb(w);
			for (int j = 0; j < 3; j++) {
				for (int k = j + 1; k < 3; k++) {
					arr[i].pb(box[i][j] * box[i][k]);
				}
			}
			sort(all(arr[i]), greater<LL>());
			LL tmp = 2 * arr[i][0] + arr[i][1];
			if (n == 1) tmp += arr[i][1] + arr[i][2];
			else if (i == 0) 
				tmp += arr[i][2];
			else if (i == n - 1) {
				tmp += arr[i][2];
				tmp += abs(arr[i][2] - arr[i - 1][2]);
			} else 
				tmp += abs(arr[i][2] - arr[i - 1][2]);
			ans += tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		