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

queue<int> cost, bill;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		cost.push(a);
	}
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		bill.push(a);
	}
	int ans = 0;
	while (!cost.empty() && !bill.empty()) {
		int firstBill = bill.front();
		int costnow = cost.front(); cost.pop();
		if (firstBill >= costnow) {
			ans++;
			bill.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}
		