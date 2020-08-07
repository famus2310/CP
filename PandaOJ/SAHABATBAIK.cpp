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

int par[1005];

void init() {
	for (int i = 0; i < 1005; i++)
		par[i] = i;
}
 
int findRoot(int x) {
	return par[x] == x ? x : par[x] = findRoot(par[x]);
}

void uni(int a, int b) {
	int roota = findRoot(a);
	int rootb = findRoot(b);
	if (roota != rootb) {
		par[roota] = rootb;
	}
}

bool isConnected(int a, int b) {
	return findRoot(a) == findRoot(b);
}

int main() {
	init();
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		uni(i, a);
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << (isConnected(a, b) ? "Dapat diketahui" : "Tidak dapat diketahui") << endl;
	}
	return 0;
}
		