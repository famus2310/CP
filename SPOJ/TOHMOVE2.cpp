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

void change(string& s, char to, char fro) {
	for (int i = 0; i < 2; i++) {
		if (s[i] == to)
			s[i] = fro;
		else if (s[i] == fro)
			s[i] = to;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		LL n, step;
		cin >> n >> step;
		LL lsb = __builtin_ffsll(step);
		string now = "AC";
		for (int i = lsb; i < n; i++) {
			if ((1LL << i) & step) {
				change(now, 'A', 'B');
			} else change(now, 'B', 'C');
		}
		cout << lsb << " : " << now[0] << " => " << now[1] << endl;
 	}
	return 0;
}
		