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

bool is_set[105];
int arr[105];

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", arr + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		is_set[a] = 1;
	}
	vector<int> ans;
	for (int i = 1; i <= 100; i++) {
		bool err = 0;
		for (int j = 0; j < n; j++) {
			if (!is_set[i + arr[j]]) {
				err = 1;
				break;
			}
		}
		if (!err)
			ans.pb(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
		