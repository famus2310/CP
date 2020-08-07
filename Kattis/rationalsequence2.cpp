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

LL solve(LL a, LL b) {
	stack<int> st; //0 left, 1 right;
	while (a > 1 || b > 1) {
		if (a > b) {
			st.push(1);
			a = a - b;
		} else {
			st.push(0);
			b = b - a;
		}
	}
	LL ret = 1LL;
	while (!st.empty()) {
		if (st.top())
			ret = ret * 2 + 1;
		else ret = ret * 2;
		st.pop();
	}
	ret = ret + 1;
	LL ansx = 
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		LL a, b;
		scanf("%lld/%lld", &a, &b);
		LL ans = solve(a, b);
		printf("%d %lld/%lld\n", x, b, );
	}
	return 0;
}
