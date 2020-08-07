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

struct node{
	int parent, sz;
};

node ds[N];
int mxsize = 1;;
set<int> lead;

void init(int a) {
	for (int i = 1; i <= a; i++) {
		ds[i].parent = i;
		ds[i].sz = 1;
		lead.insert(i);
	}
}

int findPar(int a) {
	if (ds[a].parent == a)
		return a;
	return ds[a].parent = findPar(ds[a].parent);
}

void uni(int x, int y) {
	int x_par = findPar(x);
	int y_par = findPar(y);
	if (ds[x_par].sz > ds[y_par].sz) {
		ds[x_par].sz += ds[y_par].sz;
		ds[y_par].parent = x_par;
		if (ds[x_par].sz > mxsize) {
			mxsize = ds[x_par].sz;
			lead.clear();
			lead.insert(x_par);
		} else if (ds[x_par].sz == mxsize) {
			lead.insert(x_par);
		}
	} else if (ds[x_par].sz < ds[y_par].sz) {
		ds[y_par].sz += ds[x_par].sz;
		ds[x_par].parent = y_par;
		if (ds[y_par].sz > mxsize) {
			mxsize = ds[y_par].sz;
			lead.clear();
			lead.insert(y_par);
		} else if (ds[y_par].sz == mxsize) {
			lead.insert(y_par);
		}
	} else {
		if (x_par < y_par) {
			ds[x_par].sz += ds[y_par].sz;
			ds[y_par].parent = x_par;
			if (ds[x_par].sz > mxsize) {
				mxsize = ds[x_par].sz;
				lead.clear();
				lead.insert(x_par);
			} else if (ds[x_par].sz == mxsize) {
				lead.insert(x_par);
			}
		} else {
			ds[y_par].sz += ds[x_par].sz;
			ds[x_par].parent = y_par;
			if (ds[y_par].sz > mxsize) {
				mxsize = ds[y_par].sz;
				lead.clear();
				lead.insert(y_par);
			} else if (ds[y_par].sz == mxsize) {
				lead.insert(y_par);
			}
		}
	}
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	init(n);
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int a, b;
			scanf("%d %d", &a, &b);
			uni(a, b);
		} else if (type == 2) {
			int a;
			scanf("%d", &a);
			int lead_a = findPar(a);
			ds[a].sz = ds[lead_a].sz;
			ds[lead_a].parent = ds[a].parent = a;
			if (mxsize == ds[a].sz) {
				lead.erase(lead_a);
				lead.insert(a);
			}
		} else {
			int lead_now = *(lead.begin());
			printf("%d %d\n", lead_now, mxsize);
		}
	}
	return 0;
}
		