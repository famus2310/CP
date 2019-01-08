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

string s;
stack<int> st;
stack<int> ms;

int main() {
	fastio;
	int q;
	cin >> q;
	while (q--) {
		cin >> s;
		if (s[0] == 'P' && s[1] == 'U') {
			int a;
			cin >> a;
			st.push(a);
			if (ms.empty() || ms.top() >= a) {
				ms.push(a);
			}
		} else if (s[0] == 'P' && s[1] == 'O') {
			if (!st.empty()) {
				if (ms.top() == st.top()) {
					ms.pop();
				}
				st.pop();
			} else cout << "EMPTY" << endl;
		} else {
			if (!st.empty()) {
				cout << ms.top() << endl;
			}
			else cout << "EMPTY" << endl;
		}
	}
	return 0;
}
		