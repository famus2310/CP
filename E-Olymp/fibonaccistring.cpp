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

LL n, k;
vector<int> last;
vector<int> now;

void printNow() {
	for (int i = n - 1; i >= 0; i--) cout << now[i];
	cout << endl;
}

void sum() {
	vector<int> tmp = now;
	LL rem = 0;
	for (int i = 0; i < n; i++) {
		LL res = rem + now[i] + last[i];
		now[i] = res % 2;
		rem = res / 2;
	}
	last = tmp;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) last.pb(0);
	last[0] = 1;
	for (int i = 0; i < n; i++) now.pb(0);
	now[0] = 1;
	LL cnt = 2;
	while (cnt < k) {
		sum();
		cnt++;
	}
	printNow();
	return 0;
}