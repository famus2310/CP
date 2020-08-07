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

vector<int> adjList[N];
bool bad[N];
vector<int> ans;

void bfs(LL root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (!bad[now]) {
			for (auto it : adjList[now])
				q.push(it);
		} else {
			bool rem = 1;
			for (auto it : adjList[now]) {
				rem &= bad[it];
				q.push(it);
			}
			if (rem) {
				ans.pb(now);
			}
		}
  }
}

int main() {
	int n;
	int root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1) {
			root = i + 1;
			continue;
		}
		bad[i + 1] = b;
		adjList[a].pb(i + 1);
	}
	bfs(root);
	if (ans.empty()) {
		puts("-1");
		return 0;
	}
	sort(all(ans));
	for (int it : ans)
		cout << it << " ";
	cout << endl;
	return 0;
}
		