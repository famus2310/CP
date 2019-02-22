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

int n, k;
int color[5005];
int lastColor[5005];	
int cnt[5005];

int main() {
	SET(cnt, 0);
	SET(lastColor, 0);
	scanf("%d %d", &n, &k);
	bool err = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		lastColor[a]++;
		color[i] = lastColor[a];
		if (lastColor[a] > k)
			err = 1;
		cnt[color[i]]++;
		mx = max(mx, lastColor[a]);
	}
	if (mx < k) {
		for (int i = 0; i < n && mx < k; i++) {
			if (cnt[color[i]] > 1) {
				cnt[color[i]]--;
				mx++;
				color[i] = mx;
			}
		}
	}
	if (err || mx < k)
		puts("NO");
	else {
		puts("YES");
		for (int i = 0; i < n; i++) 
			cout << color[i] << " ";
		cout << endl;
	}
	return 0;
}
		