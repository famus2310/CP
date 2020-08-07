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

set<int> s;
vector<int> v;

int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	scanf("%d %d", &a, &b);
	bool prime = 1;
	int sqr = sqrt(a);
	int sq = sqrt(b);
	for (int i = 2; i <= sqr; i++) {
		if (a % i == 0) {
			s.insert(i);
			s.insert(a / i);
			prime = 0;
		}
	}
	if (prime && a != 1) s.insert(a);
	prime = 1;
	for (int i = 2; i <= sq; i++) {
		if (b % i == 0) {
			s.insert(i);
			s.insert(b / i);
			prime = 0;
		}
	}
	if (prime && b != 1) s.insert(b);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int it : s) {
			if (a % it != 0 && b % it != 0) v.pb(it);
		}
		while (!v.empty()) {
			s.erase(v.back());
			v.pop_back();
		}
	}
	if (s.empty()) {
		puts("-1");
	} else {
		printf("%d\n", *s.begin());
	}
	return 0;
}