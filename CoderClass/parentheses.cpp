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
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int par1 = 0;
		int par2 = 0;
		bool flag = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') par1++;
			else if (s[i] == ')') par1--;
			else if (s[i] == '[') par2++;
			else par2--;
			if (par1 < 0 || par2 < 0) {
				flag = 0;
				break;
			}
		}
		if (flag) puts("ya");
		else puts("tidak");
	}
	return 0;
}
		