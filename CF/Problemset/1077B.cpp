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

int arr[105];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	//1 0 1 0 1
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		if (i + 1 >= n || i + 2 >= n) continue;
		if (i - 1 < 0 || i - 2 < 0) continue;
		if (arr[i - 2] == 1 && arr[i - 1] == 0 && arr[i + 1] == 0 && arr[i + 2] == 1) {
			ans++;
			arr[i] = 0;
		}
	}
	//1 0 1
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) continue;
		if (i + 1 >= n || i - 1 < 0) continue;
		if (arr[i - 1] == 1 && arr[i + 1] == 1) {
			ans++;
			arr[i + 1] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
		