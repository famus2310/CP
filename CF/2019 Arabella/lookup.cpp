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

vector<int> perm;
vector<vector<int> > listPerm;
map<ll, ll> mp;
ll fact = 0;
int n;

ll solve(ll a, ll b) {
	ll ret = 0ll;
	for (int i = 0; i < n; i++) {
		if (listPerm[a][i] > listPerm[b][i])
			ret += listPerm[a][i];
	}
	// mp[ret]++;
	return ret;
}

int main() {
	NeedForSpeed;
	cin >> n;
	fact = 1;
	for (int i = 0; i < n; i++) {
		perm.pb(i + 1);
	}
	do {
		listPerm.pb(perm);
	} while (next_permutation(all(perm)));
	ll ansNow = 0;
	for (int i = 0; i < listPerm.size(); i++) {
		for (int j = 0; j < listPerm.size(); j++) {
			ansNow += solve(i, j);
		}
	}
	double num = ansNow;
	double denum = listPerm.size() * listPerm.size();
	cout << num / denum << endl;
	// cout << ansNow << endl;
	cout << endl;
	// for (auto it : mp) {
	// 	cout << it.first << " " << it.second << endl;
	// }
	return 0;
}
		