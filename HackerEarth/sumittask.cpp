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
		LL os = 0LL, zs = 0LL;
		for (char c : s) {
			if (c == 'O') os++;
			else zs++;
		}
		LL ans1 = 0LL, ans2 = 0LL;
		for (char c : s) {
			if (c == 'O') ans1 += zs;
			else zs--; 
		}
		for (char c : s) {
			if (c == 'Z') ans2 += os;
			else os--;
		}
		cout << min(ans1, ans2) << endl;
	}
	return 0;
}
		