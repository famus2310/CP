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
		bool flag = 1;
		for (int i = 1; i < s.size(); i++) {
			int now = s[i] - 'a';
			int last = s[i - 1] - 'a';
			if (now < last) swap(now, last);
			if (abs(now - last) == 1 || abs(now - 26 - last) == 1) continue;
			flag = 0;
			break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
		