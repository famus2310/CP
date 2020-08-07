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

string s;
ll prefix[2 * N];

void solve() {
	string rev = s;
	reverse(all(rev));
	rev = rev + "$" + s;
	prefix[0] = -1;
	for (int i = 1,j = -1; i < rev.size(); i++) {
		while (j != -1 && rev[j + 1] != rev[i])
			j = prefix[j];
		if (rev[j + 1] == rev[i])
			j++;
		prefix[i] = j;
	}
	string ret = s;
	for (int i = prefix[rev.size() - 1] + 1; rev[i] != '$'; i++)
		ret.pb(rev[i]);
	cout << ret << endl;
}

int main() {
	NeedForSpeed;
	while (cin >> s) {
		solve();
	}
	return 0;
}
		