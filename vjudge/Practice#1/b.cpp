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

const int N = 2e5 + 5;

stack<int> st;
bool isPop[N];

int main() {
	memset(isPop, 0, sizeof isPop);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = n; i >= 1; i--) {
		st.push(i);
	}
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		st.push(a);
	}
	for (int i = 0; i < n; i++) {
		while (isPop[st.top()]) st.pop();
		isPop[st.top()] = 1;
		printf("%d\n", st.top());
		st.pop();
	}
	return 0;
}
		