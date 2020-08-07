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

LL n, m;
LL arr[25];

bool dfs() {
	queue<pair<int, int> > q;
	q.push({1, 0});
	q.push({1, arr[0]});
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		if (now.second == m) return true;
		if (now.first == n) continue;
		if (now.second > m) continue;
		q.push({now.first + 1, now.second});
		q.push({now.first + 1, now.second + arr[now.first]});
	}
	return false;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", arr + i);
	printf("%s\n", dfs() ? "bisa" : "tidak bisa");
	return 0;
}
		