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

struct query {
	string q;
	int a, b;
};

query arr[150005];
int n, m, k;

int par[50005];
int rk[50005];
vector<bool> ans;
void init() {
	for (int i = 0; i < 50005; i++) {
		par[i] = i;
		rk[i] = 1;
	}
}

int findRoot(int x) {
	return par[x] == x ? x : par[x] = findRoot(par[x]);
}

void uni(int a, int b) {
	int roota = findRoot(a);
	int rootb = findRoot(b);
	if (roota != rootb) {
		if (rk[roota] < rk[rootb])
			swap(roota, rootb);
		par[rootb] = roota;
		rk[roota] += rk[rootb];
	}
}

bool isConnected(int a, int b) {
	int roota = findRoot(a);
	int rootb = findRoot(b);
	// cout << roota << " " << rootb << endl;
	return roota == rootb;
}

int main() {
	fastio;
	init();
	cin >> n >> m >> k;
	int a, b;
	for (int i = 0; i < m; i++)
		cin >> a >> b;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s >> a >> b;
		arr[i] = {s, a, b};
	}
	int cnt = 0;
	for (int i = k - 1; i >= 0; i--) {
		if (arr[i].q[0] == 'a') {
			ans.pb(isConnected(arr[i].a, arr[i].b));
		}
		else {
			uni(arr[i].a, arr[i].b);
		}
	}
	reverse(all(ans));
	for (int i = 0; i < (int)ans.size(); i++)
		cout << (ans[i] ? "YES" : "NO") << endl; 
 	return 0;
}
		