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

struct node {
	int idx, sum;
	bool operator<(node const& other) const {
		if (sum != other.sum)
			return sum > other.sum;
		return idx < other.idx;
	}
};

node score[1005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int sum = a + b + c + d;
		score[i] = {i, sum};
	}
	sort(score + 1, score + n + 1);
	for (int i = 1; i <= n; i++) {
		if (score[i].idx == 1) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
		