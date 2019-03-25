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

struct node {
	LL a, b, k;
};

bool comp(node n1, node n2) {
	if (n1.b * n1.k != n2.b * n2.k)
		return n1.b * n1.k < n2.b * n2.k;
	else if (n1.k != n2.k)
		return n1.k < n2.k;
	else return n1.a > n2.a;
}

node arr[505];

int main() {
	LL n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL a, b, c;
		cin >> a >> b >> c;
		arr[i] = {a, b, c};
	}
	sort(arr, arr + n, comp);
	vector<node> v;
	LL mx = 0LL;
	for (LL i = 0; i < n; i++) {
		LL now = 0LL;
		for (auto it : v) {
			now += it.a;
		}
		mx = max(now, mx);
		LL temp = 0;
		for (LL j = i; j < n; j++) {
			temp = max(temp, arr[j].a);
		}
		// cout << now << " "  << temp << endl;
		mx = max(now + temp, mx);
		v.push_back(arr[i]);
		for (LL j = 0; j < v.size(); j++) {
			// debug(v[j].a);
			if (v[j].k > 0) {
				v[j].k--;
				v[j].a -= v[j].b;
			}
			v[j].a = max(v[j].a, 0LL);
			// cout << v[j].a << endl;
		}
	}
	printf("%lld\n", mx);
	return 0;
}
		