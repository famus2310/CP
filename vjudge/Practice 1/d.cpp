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

string a, b;

int main() {
	LL n;
	cin >> n;
	cin >> a >> b;
	LL ans = 0LL;
	for (int i = 0; i < (a.size() + 1) / 2; i++) {
		int cnt[27];
		vector<int> v;
		SET(cnt, 0);
		cnt[a[i] - 'a']++;
		cnt[b[i] - 'a']++;
		cnt[b[n - i - 1] - 'a']++;
		cnt[a[n - i - 1] - 'a']++;
		for (int i = 0; i < 27; i++) {
			if (cnt[i] > 0)
				v.pb(cnt[i]);
		}
		sort(all(v), greater<LL>());
		for (int it : v)
			cout << it << " ";
		cout << endl;
		if (v.size() == 2 && v[0] == 3)
			ans++;
		else if (v.size() == 3 && v[0] == 2)
			ans++;
		else if (v.size() == 4 && v[0] == 1)
			ans += 2; 
	}
	printf("%lld\n", ans);
	return 0;
}
		