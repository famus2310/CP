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

int n, m, mn, mx, f, s, t;

map<string, int> mp;
vector<string> v;
int par[N];
int sz[N];
int gradeSz[N][3];
int ansmx;

bool checkGrade(int a, int b) {
	return gradeSz[a][1] + gradeSz[b][1] <= f
	&& gradeSz[a][2] + gradeSz[b][2] <= s
	&& gradeSz[a][3] + gradeSz[b][3] <= t;
}

bool checkSize(int a, int b) {
	return sz[a] + sz[b] <= mx;
}

int findRoot(int x) {
	return (par[x] == x ? x : par[x] = findRoot(par[x]));
}

void uni(int a, int b) {
	int root_a = findRoot(a);
	int root_b = findRoot(b);
	if (root_a != root_b && checkGrade(root_a, root_b) && checkSize(root_a, root_b)) {
		par[root_b] = root_a;
		sz[root_a] += sz[root_b];
		gradeSz[root_a][1] += gradeSz[root_b][1];
		gradeSz[root_a][2] += gradeSz[root_b][2];
		gradeSz[root_a][3] += gradeSz[root_b][3];
		ansmx = max(ansmx, sz[root_a]);
	}
}


int main() {
	fastio;
	ansmx = -1;
	cin >> n >> m >> mn >> mx >> f >> s >> t;
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		mp[s] = i;
		par[i] = i;
		gradeSz[i][1] = gradeSz[i][2] = gradeSz[i][3] = 0;
		gradeSz[i][x] = 1;
		sz[i] = 1;
		v.pb(s);
	}
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		uni(mp[s1], mp[s2]);
	}
	if (ansmx < mn) {
		cout << "no groups" << endl;
		return 0;
	}
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		int root = findRoot(i);
		if (sz[root] == ansmx) {
			ans.pb(v[i]);
		}
	}
	sort(all(ans));
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
		