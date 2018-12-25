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
set<int> s;
int cnt[105];

int main() {
	memset(cnt, 0, sizeof cnt);
	int n, k;
	int mx = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		s.insert(arr[i]);
		cnt[arr[i]]++;
		mx = max(mx, cnt[arr[i]]);
	}
	int dish = (int)ceil((double)mx / (double)k);
	printf("%d\n", dish * k * s.size() - n);
	return 0;
}
		