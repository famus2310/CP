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

int cnt[10005];
int arr[129];

int main() {
	SET(cnt, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { 
		scanf("%d", arr + i);
		cnt[arr[i]]++;
	}
	sort(arr, arr + n, greater<int>());
	int x = arr[0];
	int y = 1;
	for (int i = 1; i < n; i++) {
		if (x % arr[i] != 0 || (x % arr[i] == 0 && cnt[arr[i]] == 2)) {
			y = arr[i];
			break;
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}
		