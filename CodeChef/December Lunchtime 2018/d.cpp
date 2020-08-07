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

struct node {
	int t, cnt, x, y;
	bool operator< (const node& other) const {
		if (t != other.t)
			return t < other.t;
		if (cnt != other.cnt)
			return cnt < other.cnt;
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}
};

int n, p;  
vector<int> point[2005][2]; // contain : x and count
set<pair<int, int> > cur;
set<pait<int, int> > tmp;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		refresh();
		scanf("%d %d", &n, &p);
		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (c > 0)
				point[a][1].pb(c);
			if (b < 0)
				point[a][0].pb(b);
		}
		cur.insert({0, 0});
		int ans = 0;
		for (int i = 0; i < 2000; i++) {
			tmp.clear();
			sort(all(point[i][0]));
			sort(all(point[i][1]), greater<int>());
			for (auto it : cur) {
				tmp.insert(it);
				for (int j = 0; j < point[i][0].size(); j++) {
					if (it.first - point[i][0][j] <= p) {
						tmp.insert({it.first - point[i][0][j], it.second + point[i][0].size() - j});
						ans = max(ans, its.second + point[i][0].size() - j);
					}
				}
				for (int j = 0; j < point[i][1].size(); j++) {
					if (it.first + point[i][0][j] <= p) {
						tmp.insert({it.first + point[i][0][j], it.second + j + 1});
						ans = max(ans, it.second + j + 1);
					}
				}
				for (int j = 0; j < point[])
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
		