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
	LL w, h;
};

bool comp(node n1, node n2) {
	if (n1.w != n2.w) return n1.w > n2.w;
	return n1.h > n2.h;
}

node rect[N];
LL n;
LL maxw = -1;
LL maxh = -1;
LL tmpw;
LL tmph;
set<LL> st;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rect[i].w >> rect[i].h;
	}
	sort(rect, rect + n, comp);
	node now = rect[0];
	LL ans = 1;
	for (int i = 1; i < n; i++) {
		if (rect[i].w == now.w) ans++;
		else if (rect[i].h >= now.h) {
			now = rect[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
