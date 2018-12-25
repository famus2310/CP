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

vector<int> adjList[505];
vector<pair<int, int> > node;
int deg[505];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		node.pb({a, i});
	}
	sort(all(node), greater<pair<int, int>());

	if (node.size == 1) {
		puts("YES");
		puts("0");
		return 0;
	}
	pair<int, int> firstNode = node[0];
	pair<int, int> lastNode




	return 0;
}
		