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

LL arr[10005];
LL n;
LL ans = INF;
LL sum = 0;

void bfs() {
	queue<pair<LL, LL> > q;
	q.push({0, arr[0]});
	q.push({0, 0});
	while (!q.empty()) {
		pair<LL, LL> now = q.front(); q.pop();
		if (now.first == n - 1) {
			ans = min(ans, abs(now.second - sum));
			continue;
		}
		q.push({now.first + 1, now.second + arr[now.first]});
		q.push({now.first + 1, now.second});		
	}
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
		sum += arr[i];
	}
	bfs();
	printf("%lld\n", ans);
	return 0;
}
		