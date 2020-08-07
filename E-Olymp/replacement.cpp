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

struct node{
	LL idx, val;
};

vector<node> arr;
vector<node> ans;
stack<node> st;

bool comp(node n1, node n2) {
	return n1.idx < n2.idx;
}

int main() {
	LL n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL tmp;
		cin >> tmp;
		arr.pb({i, tmp});
	}
	st.push(arr[0]);
	for (int i = 1; i < n; i++) {
		LL nxt = arr[i].val;
		if (!st.empty()) {
			node now = st.top(); st.pop();
			while (now.val < nxt) {
				ans.pb({now.idx, nxt});
				if (st.empty()) break;
				now = st.top(); st.pop();
			}
			if (now.val >= nxt) st.push(now);
		}
		st.push({i, nxt});
	}
	sort(all(ans), comp);
	int id = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		if (id < ans.size() && ans[id].idx == i) {
			cout << ans[id].val;
			id++;
		} else {
			cout << 0;
		}
	}
	cout << endl;
	return 0;
}
		