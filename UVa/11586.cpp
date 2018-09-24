#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		int m = 0, f = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'M')
				m++;
			else if (s[i] == 'F')
				f++;
		}
		// cout << m << " " << f << endl;
		printf("%s\n", (m == f && m % 2 == 0) ? "LOOP" : "NO LOOP");
	}
	return 0;
}
		