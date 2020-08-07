#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

struct query {
	ll type, a, b;
};

vector<query> qr;
ll par[N];
ll sumStr[N];
vector<pair<ll, ll> > bond;
bool deletedBond[N];
ll n, m;
vector<ll> ans;
bool visited[N];
ll segTree[4 * N];
vector<ll> lastStr[N];

void updateSeg(ll node, ll a, ll b, ll idx, ll val) {
	if (a == b) {
		segTree[node] = val;
	} else if (a <= idx && idx <= b) {
		ll mid = (a + b) / 2;
		if (a <= idx && idx <= mid)
			updateSeg(2 * node, a, mid, idx, val);
		else updateSeg(2 * node + 1, mid + 1, b, idx, val);
		segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]); 
	}
}

ll getMax() {
	return segTree[1];
}

void init() {
	for (int i = 0; i < N; i++)
		par[i] = i;
}

ll findRoot(ll x) {
	return x == par[x] ? x : par[x] = findRoot(par[x]);
}

void uni(ll a, ll b) {
	ll root_a = findRoot(a);
	ll root_b = findRoot(b);
	if (root_a != root_b) {
		par[root_a] = root_b;
		sumStr[root_b] += sumStr[root_a];
		sumStr[root_a] = 0;
	}
}


int main() {
	NeedForSpeed;
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		lastStr[i].pb(a);
	}
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		bond.pb({u, v});
	}
	ll q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll u, v, w = 0;
		cin >> u;
		if (u == 1) {
			cin >> v;
			deletedBond[v - 1] = 1;
		} else {
			cin >> v >> w;
			lastStr[v].pb(w);
		}
		qr.pb({u, v, w});
	}
	for (int i = 1; i <= n; i++) {
		sumStr[i] = lastStr[i].back();
		lastStr[i].pop_back();
	}
	for (int i = 0; i < bond.size(); i++) {
		if (deletedBond[i])
			continue;
		uni(bond[i].first, bond[i].second);
	}
	for (int i = 1; i <= n; i++) {	
		ll root_i = findRoot(i);
		if (visited[root_i])
			continue;
		visited[root_i] = 1;
		updateSeg(1, 1, n, root_i, sumStr[root_i]);
	}	
	for (int i = q - 1; i >= 0; i--) {
		ans.pb(getMax());
		query now = qr[i];
		if (now.type == 1) {
			ll root_a = findRoot(bond[now.a - 1].first);
			ll root_b = findRoot(bond[now.a - 1].second);
			if (root_a == root_b)
				continue;
			uni(root_a, root_b);
			updateSeg(1, 1, n, root_b, sumStr[root_b]);
			updateSeg(1, 1, n, root_a, 0);
		} else {
			ll curRoot = findRoot(now.a);
			ll updSum = lastStr[now.a].back() - now.b;
			lastStr[now.a].pop_back();
			sumStr[curRoot] += updSum;	
			updateSeg(1, 1, n, curRoot, sumStr[curRoot]);
		}			
	}
	reverse(all(ans));
	for (auto it : ans)
		cout << it << endl;
	return 0;
}
		