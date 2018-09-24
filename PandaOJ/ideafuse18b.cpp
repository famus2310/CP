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

const int N = 1e5 + 5;

string s;
int cnt[35];
int tmp[35];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		cin >> s;
		set<int> fact;
		for (int i = 1; i <= sqrt(n); i++) {
			if (n % i == 0) {
				fact.insert(i);
				fact.insert(n / i);
			}
		}
		int ans = 1;
		for (auto it : fact) {
			int res = n / it;
			memset(cnt, 0, sizeof cnt);
			for (int i = 0; i < it; i++) {
				cnt[s[i] - 'A']++;
			}
			for (int i = it; i < n; i += it) {
				memset(tmp, 0, sizeof tmp);
				for (int j = i; j < i + it; j++) {
					tmp[s[j] - 'A']++;
				}
				for (int i = 0; i < 26; i++) {
					if (cnt[i] != tmp[i]) {
						res = 1;
						break;
					}
				}
				if (res == 1) break;
			}
			ans = max(ans, res);
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
		