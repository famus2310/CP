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

bool checker(vector<int> tmp, int k) {
	if (tmp.size() == 1) return true;
	for (int i = 1; i < tmp.size(); i++) if (abs(tmp[i] - tmp[i - 1]) > k) return false;
	return true;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> now;
	for (int i = 1; i <= n; i++) now.pb(i);
	do {
		if (checker(now, k)) {
			for (int i = 0; i < n; i++) printf("%d%c", now[i], i == n - 1 ? '\n' : ' ');	
		}
	} while (next_permutation(all(now)));
	return 0;
}
		