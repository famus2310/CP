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

const int N = 1e6 + 5;

int player[N];
int dir[105];

void init() {
	for (int i = 0; i < N; i++)
		player[i] = 1;
	for (int i = 0; i < 105; i++)
		dir[i] = i;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		int a, b, c;
		bool win = 0;
		scanf("%d %d %d", &a, &b, &c);
		for (int i = 0; i < b; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			dir[u] = v;
		}
		for (int i = 0; i < c; i++) {
			int w;
			scanf("%d", &w);
			if (win) continue;
			player[i % a] += w;
			player[i % a] = dir[player[i % a]];
			if (player[i % a] == 100) win = 1;
		}
		for (int i = 0; i < a; i++) {
			printf("Position of player %d is %d.\n", i + 1, player[i]);
		}
	}
	return 0;
}
		