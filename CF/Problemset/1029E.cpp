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

const int N = 2e5 + 5;

vector<int> adjList[N];
set<int> s;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[a].pb(b);
		adjList[b].pb(a);
		s.insert(i + 2);
	}
	int ret = 0;
	for (int it : adjList[1]) {
		s.erase(it);
		for (int at : adjList[it])
			s.erase(at);
	}
	while (!s.empty()) {
		ret++;
		for (int it : adjList[*s.begin()]) {
			s.erase(it);
		}
		s.erase(*s.begin());
	}
	printf("%d\n", ret);
	return 0;
}
		