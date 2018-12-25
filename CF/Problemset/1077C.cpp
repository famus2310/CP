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

int cnt[N * 10];
int arr[2 * N];
vector<int> ans;

int main() {
	SET(cnt, 0);
	int n;
	scanf("%d", &n);
	LL total = 0LL;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		cnt[arr[i]]++;
		total += arr[i];
	}
	for (int i = 0; i < n; i++) {
		LL tmp = total - arr[i];
		if (tmp & 1) continue;
		if (tmp / 2 >= N * 10) continue; 
		cnt[arr[i]]--;
		if (cnt[tmp / 2]) ans.pb(i);
		cnt[arr[i]]++;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i] + 1, i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
		