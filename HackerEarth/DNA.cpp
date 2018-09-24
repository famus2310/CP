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
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		bool flag = 1;
		string ans;
		for (char c : s) {
			if (c == 'A') ans.pb('T');
			else if (c == 'T') ans.pb('A');
			else if (c == 'G') ans.pb('C');
			else if (c == 'C') ans.pb('G');
			else {
				flag = 0;
				break;
			}
		}
		if (flag) cout << ans << endl;
		else cout << "Error RNA nucleobases found!" << endl;
	}
	return 0;
}
		