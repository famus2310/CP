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

const int NMAX = 1e5 + 5;


int main() {
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	for (int i = a; i <= b; i++) {
		int x = sqrt(i);
		if (i  == x * x) cnt++;
	}
	cout << cnt << endl;	
	return 0;
}
		