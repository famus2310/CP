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

vector<int> factorized;

int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	scanf("%d %d", &a, &b);
	int sqa = sqrt(a), sqb = sqrt(b);
	for (int i = 2; i <= sqa; i++) {
		if (a % i == 0) {
			factorized.pb(i);
			while (a % i == 0)
				a /= i;
		}
	}

	for (int i = 2; i <= sqb; i++) {
		if (b % i == 0) {
			factorized.pb(i);
			while (b % i == 0)
				b /= i;
		}
	}

	if (a != 1) factorized.pb(a);
	if (b != 1) factorized.pb(b);
	sort(all(factorized));
	factorized.erase(unique(all(factorized)), factorized.end());
	// factorized.erase(factorized.begin());
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		int j = 0;
		while (!factorized.empty() && j < factorized.size()) {
			// debug(factorized[j]);
			if (a % factorized[j] != 0 && b % factorized[j] != 0)
				factorized.erase(factorized.begin() + j);
			else j++;
		}
	}
	if (factorized.empty())
		puts("-1");
	else printf("%d\n", factorized[0]);
	return 0;
}
		