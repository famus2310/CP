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

int n, p;

int main() {
	int tc = 1;
	while (cin >> n >> p, (n || p)) {
		if (tc != 1) cout << endl;
		cin.ignore();
		// cout << n << p << endl;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			// debug(s);
		}
		string ans;
		int comp;
		double price;
		getline(cin, ans);
		// debug(ans);
		cin >> price >> comp;
		cin.ignore();
		for (int i = 0; i < comp; i++) {
			string s;
			// cin.ignore();
			getline(cin, s);
		}
		// debug(comp);
		for (int i = 1; i < p; i++) {
			string s;
			getline(cin, s);
			int m;
			double pr;
			cin >> pr >> m;
			cin.ignore();
			for (int i = 0; i < m; i++) {
				string tmp;
				getline(cin, tmp);
			}
			if (m > comp || (m == comp && pr < price)) {
				ans = s;
				comp = m;
			}
		}
		cout << "RFP #" << tc++ << endl;
		cout << ans << endl;
	}
	return 0;
}
		