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

ll n, m;
string s;
ll root[50005];
ll content[50005];
bool vis[50005];

void init() {
	for (int i = 0; i < s.size(); i++) {
		root[i] = i;
		content[i] = isalpha(s[i]) ? (1 << (s[i] - 'a' + 1)) : 1;
		vis[i] = 0;
	}
}

ll findRoot(ll x) {
	return root[x] == x ? x : root[x] = findRoot(root[x]);
}

void uni(ll a, ll b) {
	ll root_a = findRoot(a);
	ll root_b = findRoot(b);
	if (root_a != root_b) {
		root[root_a] = root_b;
		content[root_b] |= content[root_a];
	}
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cin >> s;
		init();
		for (int i = 0; i < m; i++) {
			ll x, y;
			cin >> x >> y;
			uni(x - 1, y - 1);
		}
		for (int i = 0; i < s.size() / 2; i++)
			uni(i, s.size() - i - 1);
		bool able = 1;
		ll ans = 1ll;
		for (int i = 0; i < s.size(); i++) {
			int curRoot = content[findRoot(i)];
			int popcount = __builtin_popcount(curRoot);
			if (popcount == 1) {
				if (curRoot & 1) {}
				else s[i] = ('a' + __builtin_ctz(curRoot) - 1);
			} else if (popcount == 2) {
				if (curRoot & 1) {
					curRoot--;
					s[i] = ('a' + __builtin_ctz(curRoot) - 1);
				} else able = 0;
			} else able = 0;
		}
		for (int i = 0; i < s.size() / 2; i++) 
			if (s[i] != s[s.size() - i - 1])
				able = 0;
		if (!able) {
			cout << 0 << endl;
		} else {
			for (int i = 0; i < (s.size() + 1)/ 2; i++) {
				ll curroot = findRoot(i);
				if (vis[curroot])
					continue;
				vis[curroot] = 1;
				if (s[i] == '?')
					ans = (ans * 26) % MOD;
			}
			cout << ans % MOD << endl;
		}
	}
	return 0;
}
	/*
4
5 1
ma??m
1 5

5 4
ma??m
1 2
1 5
1 3
3 4

7 0
acm?cpc

4 1
????
1 4 

	*/