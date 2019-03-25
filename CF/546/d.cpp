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

LL arr[3 * N];
LL pos[3 * N];
LL behind[3 * N];
vector<int> affect[3 * N];

int main() {
	SET(behind, 0);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", arr + i);
		pos[arr[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		affect[b].pb(a);
		if (pos[b] > pos[a])
			behind[a]++;
	}
	// cur[arr[n]] = 1;
	int ans = 0;
	int cur = 1;
	for (int i = n - 1; i > 0; i--) {
		if (behind[arr[i]] == cur) {
			ans++;
			for (auto it : affect[arr[i]]) {
				// cout << it << endl;
				behind[it]--;
			}
		} else {
			cur++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
		