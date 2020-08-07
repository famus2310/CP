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

bool vis[105];
queue<int> q;
int weight[2005];
int car[2005];
int rate[105];

int findPark(int x) {
	for (int i = 1; i <= x; i++) {
		if (!vis[i])
			return i;
	}
	return -1;
}


int main() {
	memset(vis, 0, sizeof vis);
	memset(car, -1, sizeof car);
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", rate + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", weight + i);
	for (int i = 1; i <= 2 * m; i++) {
		int a;
		scanf("%d", &a);
		if (a > 0) {
			int park = findPark(n);
			if (park == -1)
				q.push(a);
			else {
				vis[park] = 1;
				ans += weight[a] * rate[park];
				car[a] = park;
			}
		} else {
			a = -a;
			int park = car[a];
			vis[park] = 0;
			if (!q.empty()) {
				int now = q.front(); q.pop();
				vis[park] = 1;
				ans += weight[now] * rate[park];
				car[now] = park;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
		