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

string spec, s;
LL n;

int main() {
	scanf("%lld", &n);
	cin >> spec;
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		LL change = 0;
		LL lens = s.size();
		LL specs = spec.size();
		if (abs(lens - specs) > 1) continue;
		int j = 0;
		for (int i = 0; i < spec.size() && change < 2; i++) {
			if (spec[i] != s[j]) {
				if (s.size() < spec.size()) {
					j--;
				} else if (s.size() > spec.size()) {
					j++;
				}
				change++;
			}
			j++;
		}
		if (change < 2) ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
		