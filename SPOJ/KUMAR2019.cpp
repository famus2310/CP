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

int can[2005];
bool vis[1005][1005];

void BFS(int x, int y) {
	for (int i = 0; i < 2005; i++)
		can[i] = INF;
	queue<pair<int, pair<int, int> > > q;
	can[0] = 0;
	vis[0][0] = 1;
	q.push({0, {0, 0}});
	if (x == 0 & y == 0)
		return;
	else if (x == 0) {
		can[y] = 1;
		return;
	} else if (y == 0) {
		can[x] = 1;
		return;
	}
	while (!q.empty()) {
		int a = q.front().second.first;
		int b = q.front().second.second;
		int step = q.front().first;
		// cout << a << " " << b << " " << step << endl;
		q.pop();
		//a -> b
		int nowa, nowb;
		nowa = 0;
		nowb = min(a + b, y);
		if (!vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//b -> a
		nowa = min(a + b, x);
		nowb = 0;
		if (!vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//fill a
		nowa = x;
		nowb = b;
		if (!vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//fill b
		nowa = a;
		nowb = y;
		if (!vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//a -> b until b full
		int diff = (y - b);		
		nowb = y;
		nowa = a - (diff);
		if (nowa >= 0 && !vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//b -> a untill a full
		diff = (x - a);
		nowa = x;
		nowb = b - diff;
		if (nowb >= 0 && !vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//empty a
		nowa = 0;
		nowb = b;
		if (!vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
		//empty b
		nowa = a;
		nowb = 0;
		if (!vis[nowa][nowb]) {
			q.push({step + 1, {nowa, nowb}});
			can[nowa] = min(can[nowa], step + 1);
			can[nowb] = min(can[nowb], step + 1);
			can[nowa + nowb] = min(can[nowa + nowb], step + 1);
			vis[nowa][nowb] = 1;
		}
	}
}

int main() {
	int x, y;
	cin >> x >> y;
	BFS(x, y);
	int q;
	cin >> q;
	for (int tc = 1; tc <= q; tc++) {
		int a;
		cin >> a;
		cout << "Case " << tc << ": ";
		if (can[a] == INF)
			cout << "Damn!!" << endl;
		else cout << can[a] << endl;
	}
	return 0;
}
		