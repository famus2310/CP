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


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		priority_queue<int, vector<int>, greater<int>> pq;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			pq.push(a);
		}
		int now = pq.top(); pq.pop(); pq.pop();
		int now2 = pq.top();
		while (!pq.empty()) pq.pop();
		printf("%d %d %d %d\n", now, now, now2, now2);
	}
	return 0;
}
		