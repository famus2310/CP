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

const int N = 1e6 + 5;

bool arr[N];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[a] = true;
	}
	while (q--) {
		int a;
		scanf("%d", &a);
		if (arr[a]) puts("ada");
		else puts("tidak ada");
	}
	return 0;
}
		