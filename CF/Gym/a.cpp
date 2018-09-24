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

unordered_map<int, int> mp;
int arr[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int cnt = 0;
		mp.clear();
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			if (mp[arr[i]] == 0 && arr[i] != 0) cnt++;
			mp[arr[i]]++;
		}
		while (q--) {
			int type;
			scanf("%d", &type);
			if (type == 1) {
				int p, v;
				scanf("%d %d", &p, &v);
				mp[arr[p - 1]]--;
				if (mp[arr[p - 1]] == 0 && arr[p - 1] != 0) cnt--;
				if (mp[v] == 0 && v != 0) cnt++;
				mp[v]++;
				arr[p - 1] = v;
			} else {
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
		