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

class SegTree {
private:
	vector<int> st[35], lazy[35];
	int n;

public:
	SegTree(int _n) {
		for (int i = 0; i < 35; i++) {
			st.assign(4 * _n, 0);
			lazy.assign(4 * _n, -1);
		}
		n = _n;

	}

	void build(int node, int ch, int lo, int hi) {
		if (lo == hi) {
			
		}
	}

	void push(int node, int ch, int lo, int hi) {
		if (lazy[ch][node] != -1) {
			st[ch][node] = lazy[ch][node] * (hi - lo + 1);
			if (lo != hi) {
				lazy[ch][node >> 1] = lazy[ch][node >> 1 | 1] = lazy[ch][node];
			}
			lazy[ch][node] = -1;
		} 
	}

	void upd(int node, int ch, int lo, int hi, int a, int b, int val) {
		push(node, ch, lo, hi);
		if (lo > b || hi < a)
			return;
		if (lo <= a && b <= hi) {
			lazy[ch][node] = val;
			push(node, ch, lo, hi);
			return;
		}
		int mid = lo + (hi - lo) / 2;
		upd(node >> 1, ch, lo, mid, a, b, val);
		upd(node >> 1 | 1, ch, mid + 1, hi, a, b, val);
		st[node] = st[node >> 1] + st[node >> 1 | 1];
	}

	int get(int node, int ch, int lo, int hi, int a, int b) {
		push(node, ch, lo, hi);
		if (lo > b || hi < a)
			return 0;
		if (lo <= a && b <= hi) {
			push(node, ch, lo, hi);
			return st[ch][node];
		}
		int mid = lo + (hi - lo) / 2;
		return get(st, ch, lo, mid, a, b) + get(st, ch, mid + 1, hi, a, b);
	}

	int getAns(int node, int ch, int k) {
		int lo = 0; hi = n - 1;
		while (hi - lo > 1) {
			int mid = lo + (hi - lo) / 2;
			if (get(1, ch, 1, n - 1, 0, mid) >= k) 
				hi = mid - 1;
			else lo = mid + 1;
		}
		if (hi < lo) swap(hi, lo);
		if (get(1, ch, 1, n - 1, 0, lo) == k)
			return lo;
		else if (get(1, ch, 1, n - 1, 0, hi) == k)
			return hi;
		return -1;
	}
};

int main() {
	fastio;
	string s;
	cin >> s;
	SegTree stree;
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 0) {
			int a, b;
			char c;
			cin >> a >> b >> c;
			for (int i = 0; i < 30; i++) {
				if (i == c - 'a') 
					upd()
			}
		}
	}
	return 0;
}
		