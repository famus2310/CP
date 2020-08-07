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

vector<int> ans;

int main() {
	int a;
	int last = -1;
	int cnt = 0;
	while (scanf("%d", &a) == 1) {
		if (last == -1) {
			last = a;
			cnt = 1;
		} else if (a == last) {
			cnt++;
			if (cnt == 255) {
				ans.pb(cnt);
				ans.pb(last);
				cnt = 0;
			}
		}
		else if (a != last) {
			if (cnt != 0) {
				ans.pb(cnt);
				ans.pb(last);
			}
			last = a;
			cnt = 1;
		}
	}
	if (cnt != 0) {
		ans.pb(cnt);
		ans.pb(last);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i += 2) {
		if (i != 0) cout << " ";
		cout << ans[i] << " " << ans[i + 1]; 
	}
	cout << endl;
	return 0;
}
		