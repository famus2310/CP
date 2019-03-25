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


inline void scanint(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

struct node {
	int query, last, color;
	bool operator< (const node& other) const {
		return query < other.query;	
	}
};

priority_queue<node> pq;
vector<node> arr[200005];

int main() {
	int n, k;
	scanint(n);
	scanint(k);
	for (int i = 0; i < k; i++) {
		int a, b, x;
		scanint(a);
		scanint(b);
		scanint(x);
		arr[a].pb({i, b, x});
	}
	for (int i = 1; i <= n; i++) {
		if (!arr[i].empty()) {
			for (int j = 0; j < arr[i].size(); j++) 
				pq.push(arr[i][j]);
		}
		while (!pq.empty() && pq.top().last < i) {
			pq.pop();
		}
		if (pq.empty())
			printf("0\n");
		else printf("%d\n", pq.top().color);
	}
	return 0;
}
		