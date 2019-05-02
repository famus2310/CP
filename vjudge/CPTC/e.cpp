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

vector<int> arr;

int main() {
	int n, p;
	while (scanf("%d %d", &n, &p) == 2) {
		int t = 0;
		arr.clear();
		int total = 0;
		int probs = 1;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			if (i == p) {
				total += a;
				t += a;
			}
			else arr.pb(a);
		}
		sort(all(arr));
		int i = 0;
		// debug(t);
		while (i < n - 1 && t + arr[i] <= 300) {
			t += arr[i];
			total += t;
			i++;
			probs++;
		}
		if (t <= 300) {
			printf("%d %d\n", probs, total);
		} else puts("0 0");
	}
	return 0;
}
		