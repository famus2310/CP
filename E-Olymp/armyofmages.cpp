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

struct point {
	int x, y;
};

point arr[25005];
bool ok[25005];
vector<pii> ans;

bool check(int a, int b) {
	int dx = abs(arr[a].x - arr[b].x);
	int dy = abs(arr[a].y - arr[b].y);
	return __gcd(dx, dy) != 1; 
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 5 * n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i] = {x, y};
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ok[i] || ok[j])
				continue;
			if (check(i, j)) {
				cout << i << j << endl;
				ok[i] = 1;
				ok[j] = 1;
				ans.pb({i + 1, j + 1});
			}
		}
	}
	if (ans.size() >= n) {
		puts("OK");
		for (auto it : ans)
			printf("%d %d\n", it.first, it.second);
	} else puts("IMPOSSIBLE");
	return 0;
}
		