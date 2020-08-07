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

set<int> st;
int arr[105];

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m), n || m) {
		st.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d", arr + i);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				st.insert(abs(arr[i] - arr[j]));
			}
		} 
		if (st.size() == n + 1) puts("Y");
		else puts("N");
	}
	return 0;
}
		