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
string s;

LL cnt[5];
LL arr[N];

int main() {
	SET(cnt, 0);
	int n;
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'h') {
			if (cnt[0] == 0) {
				SET(cnt, 0);
			}
			cnt[0] += arr[i];
		}
		if (s[i] == 'a') {
			if (cnt[1] == 0) {
				cnt[2] = cnt[3] = 0;
			}
			cnt[1] += arr[i];
		}
		if (s[i] == 'r') {
			if (cnt[2] == 0)
				cnt[3] = 0;
			cnt[2] += arr[i];
		}
		if (s[i] == 'd') {
			cnt[3] += arr[i];
			if (cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 && cnt[3] != 0) {
				if (cnt[3] <= cnt[1] && cnt[3] <= cnt[2] && cnt[3] <= cnt[0]) {
					ans += cnt[3];
					cnt[3] = 0;
				}
				if (cnt[0] <= cnt[1] && cnt[0] <= cnt[2]) {
					ans += cnt[0];
					cnt[0] = 0;
				} else if (cnt[1] <= cnt[2]) {
					ans += cnt[1];
					cnt[1] = 0;
				} else {
					ans += cnt[2];
					cnt[2] = 0;
				}
			}
		}
 	}
 	printf("%lld\n", ans);
	return 0;
}
		