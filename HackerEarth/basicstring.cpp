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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int a, b;
		scanf("%d %d", &a, &b);
		string k = s.substr(a, b - a + 1);
		sort(all(k), greater<char>());
		// debug(k);
		string ans = s.substr(0, a) + k + s.substr(b + 1);
		cout << ans << endl;
	}
	return 0;
}
		