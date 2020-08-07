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

int cur[N];
int pos[N];
int cnt;

int solve(int a, int now, int idx) {
	if (cur[idx] == idx) return 0;
	int tmp = a > now ? now + 1 : now - 1;
	int tmp1 = cur[tmp];
	swap(pos[cur[tmp]], pos[now]);
	swap(cur[tmp], cur[idx]);
	return 1 + solve(a, tmp, idx); 
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", cur + i);
			pos[cur[i]] = i;
		}		
		for (int i = 1; i <= n; i++) {
			if (cur[i] != i)
				cnt += solve(i, cur[i], i);
			for (int j = 1; j <= n; j++)
				cout << cur[j] << " ";
			cout << endl;
			debug(cnt);
		}
		cout << cnt << endl;
	}
	return 0;
}
		