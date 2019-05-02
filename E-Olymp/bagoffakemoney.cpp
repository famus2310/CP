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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int freq[100005];
int arr[100005];

int main() {
	SET(freq, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	if (n == 1) {
		puts("0");
		return 0;
	}
	sort(arr, arr + n);
	deque<pair<int, int> > rem;
	int now = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (rem.empty())
			rem.pb({arr[i], 1});
		else if (rem.back().first == arr[i]) {
			int tmp = rem.back().second + 1;
			rem.pop_back();
			rem.pb({arr[i], tmp});
		} else {
			rem.pb({arr[i], 1});
		}
	}
	// assert(rem.front().first == 1 || rem.back().first == 1);
	while (!rem.empty()) {
		ans++;
		now = 1;
		int last = 0;
		deque<pair<int, int> > q;
		while (!rem.empty()) {
			int cur = rem.front().first;
			int cnt = rem.front().second;
			rem.pop_front();
			if (cnt == 1)
				cnt = 0;
			else cnt = cnt / (cur - last + 1) + (cnt % (cur - last + 1) != 0);
			last = cur;
			if (cnt != 0)
				q.push_back({cur, cnt});
		}
		if (q.empty() || (q.size() == 1 && q.front().second == 1)) {
			printf("%d\n", ans);
			return 0;
		}
		while (!q.empty()) {
			rem.push_back(q.front());
			q.pop_front();
		}
	}
	return 0;
}
		