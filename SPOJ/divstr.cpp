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

string a, b;

int main() {
	LL t;
	cin >> t;
	cin.ignore();
	while (t--) {
		getline(cin, a);
		getline(cin, b);
		LL cnt = 0;
		LL now = 0;
		for (int i = 0; i < a.size(); i++) {
			if (b[now] == a[i]) {
				now++;
				if (now == b.size()) {
					now = 0;
					cnt++;
				}
			}
		}
		cout << a.size() - b.size() * cnt << endl;
	}
	return 0;
}
		