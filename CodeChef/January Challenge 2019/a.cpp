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

map<int, bool> vis;
pair<int, int> a[2 * N], b[2 * N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = {x, i};
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		b[i] = {x, i};
	}
	sort(a, a + n);
	sort(b, b + m);
	int cnt = n + m - 1;
	if (n >= m) {
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", a[i].second, b[0].second);
			cnt--;
		}
		for (int i = n - 1; i >= 0 && cnt; i--) {
			printf("%d %d\n", a[i].second, b[m - 1].second);
			cnt--;
		}
	} else {
		for (int i = 0; i < m; i++) {
			printf("%d %d\n", a[0].second, b[i].second);
			cnt--;
		}
		for (int i = m - 1; i >= 0 && cnt; i--) {
			printf("%d %d\n", a[n - 1].second, b[i].second);
			cnt--;
		}
	}
	return 0;
}
		