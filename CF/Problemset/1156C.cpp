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

vector<LL> v;
bool used[2 * N];

int main() {
	fastio;
	LL n, z;
	cin >> n >> z;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		v.pb(a);
	}
	int i = 0;
	int j = v.size() / 2;
	LL ans = 0LL;
	sort(all(v));
	while (i < v.size() && j < v.size()) {
		if (used[i])
			i++;
		else if (used[j])
			j++;
		else if (v[j] - v[i] < z) 
			j++;
		else {
			ans++;
			used[i] = 1;
			used[j] = 1;
			j++;
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}
		