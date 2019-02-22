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

char arr[1005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		LL n, k;
		scanf("%lld %lld", &n, &k);
		LL ans = 0LL;
		for (int i = 0; i < n; i++) {
			priority_queue<LL, vector<LL>, greater<LL> > pq;
			for (int j = 0; j < n; j++) {
				scanf(" %c", arr + j);
				if (arr[j] == 'T')
					pq.push(j);
			}
			for (int j = 0; j < n && !pq.empty(); j++) {
				if (arr[j] == 'T')
					continue;
				while (!pq.empty()) {
					LL now = pq.top();
					// cout << j << " " << now << endl;
					pq.pop();
					if (abs(j - now) <= k) {
						ans++;
						break;
					} else if (now > j) {
						pq.push(now);
						break;
					}
				}
			}
			// debug(ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
		