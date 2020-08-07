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

const int NMAX = 1e5 + 5;

int n;
vector<vector<int> > cur, ans;

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] |= cur[i][j];
		}
	}
}

void rot() {
	vector<vector<int> > tmp = cur;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cur[i][j] = tmp[n - j - 1][i];
		}
	}
}

void printAns() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(j != 0) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cur.pb(vector<int>());
		ans.pb(vector<int>());
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			cur[i].pb(a); ans[i].pb(a);
		}
	}
	rot(); solve();
	rot(); solve();
	rot(); solve();
	printAns();
	return 0;
}
		