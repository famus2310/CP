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

bool grouped[105];
int cnt[105][35];
char pre[105][2];

bool isAnagram(int a, int b) {
	for (int i = 0; i < 26; i++) {
		if (cnt[a][i] != cnt[b][i]) return false;
	}
	return true;
}

int main() {
	SET(cnt, 0);
	SET(grouped, 0);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			cnt[i][c - 'a']++;
		}
		pre[i][0] = s[0];
		pre[i][1] = s.back();
		bool found = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (!isAnagram(i, j) || pre[i][0] != pre[j][0] || pre[i][1] != pre[j][1]) continue;
			found = 1;
			break;
		}
		if (!found) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
		