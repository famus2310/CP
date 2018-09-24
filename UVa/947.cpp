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

int a, b;
string s;

void generate(string now, int& ans) {
	if (now.size() == s.size()) {
		int tmpA = 0, tmpB = 0;
		int cntNow[15], cntS[15];
		SET(cntNow, 0);
		SET(cntS, 0);
		for (int i = 0; i < now.size(); i++) {
			if (now[i] == s[i]) tmpA++;
			else {
				cntNow[now[i] - '0']++;
				cntS[s[i] - '0']++;
			}
		}
		for (int i = 1; i < 10; i++) {
			tmpB += min(cntNow[i], cntS[i]);
		}
		if (tmpA == a && tmpB == b) ans++;
	} else {
		for (int i = 1; i < 10; i++) {
			generate(now + to_string(i), ans);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		cin >> s >> a >> b;
		int ans = 0;
		generate("", ans);
		printf("%d\n", ans);
	}
	return 0;
}
		