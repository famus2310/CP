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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;
bool arr[13];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(arr, 0);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			int a;
			scanf("%d", &a);
			arr[a] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!arr[i]) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
		