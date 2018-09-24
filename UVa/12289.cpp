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

string s[] = {"one", "two", "three"};
string inp;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> inp;
		int wrong;
		for (int i = 0; i < 3; i++) {
			wrong = 0;
			if (inp.size() != s[i].size()) continue;
			for (int j = 0; j < s[i].size() && wrong < 2; j++) {
				if (s[i][j] != inp[j]) wrong++;
			}
			if (wrong < 2) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
		