#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <functional>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define mp make_pair
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))


string a, b;
int n;
int dp[5][5005];


int solve(int lo, int hi) {
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			if (i == 0 || j == 0)
				dp[i % 2][j] = 0;
			else if (a[i - 1] == b[j - 1])
				dp[i % 2][j] = 1 + dp[(i + 1) % 2][j - 1];
			else 
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
		}
	}
	return dp[a.size() % 2][b.size()];
}

int main() {
	cin >> n >> a;
	b = a;
	reverse(all(b));
	cout << a.size() - solve(0, n - 1) << endl;
	return 0;
}
		