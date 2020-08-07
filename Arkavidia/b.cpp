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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string s1, s2;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> s1 >> s2;
		if (s1.size() < s2.size())
			swap(s1, s2);
		int g = __gcd(s1.size(), s2.size());
		bool fnd = 1;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i % g])
				fnd = 0;
		}
		string ans = s1.substr(0, g);
		if (fnd)
			cout << ans << endl;
		else cout << "-" << endl;
	}
	return 0;
}
		