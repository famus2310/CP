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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


vector<pair<int, int> > v;

bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		v.clear();
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.pb({a, b});
		}
		sort(all(v), comp);
		queue<pair<int, int> > q;
		for (auto it : v)
			q.push(it);
		int ans = 0;
		int mn = INF;
		for (int i = 1; i <= 2 * N + 5; i++) {
			while (!q.empty() && q.front().first == i) {
				mn = min(mn, q.front().second);
				q.pop();
			}
			if (mn == i) {
				ans++;
				mn = INF;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
3
1  2
2  4
5  6
5
1  2
3  5
4  6
7  9
8  10
*/