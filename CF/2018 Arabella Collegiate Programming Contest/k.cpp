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

string sub1, sub2;
string a, b;

bool solve() {
	if (sub1.empty())
		return true;
	ll sz = sub1.size();
	//kiri
	bool ans1 = 1;
	bool ans2 = 1;
	for (int i = 0; i < sub1.size(); i++) {
		if (sub1[i] != sub2[(i + 1) % sz])
			ans1 = 0;
	}
	for (int i = 0; i < sub1.size(); i++) {
		if (sub1[i] != sub2[(i - 1 + sz) % sz])
			ans2 = 0;
	}
	return ans1 or ans2;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		sub1.clear();
		sub2.clear();
		int n;
		cin >> n;
		cin >> a >> b;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				sub1.pb(a[i]);
				sub2.pb(b[i]);
			}
		}
		if (solve())
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
		