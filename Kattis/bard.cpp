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

const int NMAX = 1e5 + 5;


set<int> vil[105];

int main() {
	int n;
	scanf("%d", &n);
	int t;
	scanf("%d", &t);
	int cnt = 0;
	for (int i = 0; i < t; i++) {
		bool bard = 0;
		int m;
		scanf("%d", &m);
		vector<int> now;
		for (int j = 0; j < m; j++) {
			int a;
			scanf("%d", &a);
			if (a == 1) {
				bard = 1;
				cnt++;
			}
			now.pb(a);
		}
		if (bard) {
			for (int j = 0; j < m; j++) {
				vil[now[j]].insert(i);
			}
		} else {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					if (j == k) continue;
					for (auto it : vil[now[k]]) {
						vil[now[j]].insert(it);
					}
				}
			}
		}
	}
	puts("1");
	for (int i = 2; i <= n; i++) {
		if (vil[i].size() == cnt) {
			printf("%d\n", i);
		}
	}
	return 0;
}
		