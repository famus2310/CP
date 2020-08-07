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

LL person[N];

LL solve(LL t) {
	if (t > 3)
		return person[0] + person[t - 1] + min(2 * person[1], person[0] + person[t - 2]) + solve(t - 2);
	else if (t == 1) return person[0];
	else if (t == 2) return max(person[1], person[0]);
	else return max(person[1], person[0]) + max(person[0], person[2]) + person[0]; 
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%lld", person + i);
	sort(person, person + n);
	LL ans = solve(n);
	printf("%lld\n", ans);
	return 0;
}
		