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

const int N = 1e7 + 5;

LL arr[N], n, k;
vector<LL> mask;
set<vector<LL> > st;

void dfsToMask(LL now) {
	if (arr[now * 2] == -1 && arr[now * 2 + 1] == -1) {
		mask.pb(now);
	}
	if (arr[now * 2] != -1) dfsToMask(now * 2);
	if (arr[now * 2 + 1] != -1) dfsToMask(now * 2 + 1);
}

void propagate(LL a, LL now) {
	if (arr[now] == -1) {
		arr[now] = a;
		return;
	}
	if (a > arr[now]) {
		propagate(a, 2*now + 1);
		return;
	}
	propagate(a, 2*now);
	return;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		memset(arr, -1, sizeof arr);
		for (int i = 0; i < k; i++) {
			LL a; cin >> a;
			propagate(a, 1);
		}
		mask.clear();
		dfsToMask(1);
		//cout << bitset<64>(mask) << endl;
		st.insert(mask);
	}
	cout << st.size() << endl;
	return 0;
}
		