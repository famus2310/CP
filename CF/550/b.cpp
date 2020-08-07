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

vector<int> odd;
vector<int> even;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a & 1)
			odd.pb(a);
		else even.pb(a);
	}
	sort(all(odd));
	sort(all(even));
	int turn;
	if (odd.size() > even.size())
		turn = 0;
	else turn = 1;
	while (1) {
		if (turn == 0) {
			if (odd.empty())
				break;
			odd.pop_back();
		}
		else {
			if (even.empty())
				break;
			even.pop_back();
		}
		turn = turn ^ 1;
	}
	LL sum = 0LL;
	for (auto it : odd)
		sum = sum + (LL)it;
	for (auto it : even)
		sum = sum + (LL)it;
	printf("%lld\n", sum);	
	return 0;
}
		