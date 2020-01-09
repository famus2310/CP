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

int f(int, int, int);

int F(int m, int k, int j) {
	int ret = 0;
	for (int i = 1; i <= j; i++)
		ret = ret + f(m, k, i);
	return ret;
}

int C[1005][1005];

void precomp() {
	C[0][0] = 0;
	for (int i = 1; i < 1005; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
}

int f(int m, int k, int l) {
	// cout << m << " " << k << " " << l << endl;
	if (k == 0)
		return 1;
	if (k == m)
		return 0;
	if (l == 1)
		return 1;	
	if (l == C[m][k])
		// return C[m - 1][k];
		return 0;
	if (1 <= l && l <= C[m - 1][k - 1])
		return f(m - 1, k - 1, l);
	return f(m - 1, k, l - C[m - 1][k - 1]);
	// return C[m - 2][k - 1] + F(m - 1, k, l - C[m - 1][k - 1]);
}

int main() {
	precomp();
	for (int m = 1; m <= 6; m++) {
		int k = 0;
		int timer = C[m][0];
		int reall = 1;
		for (int l = 0; l < (1LL << (m)); l++) {
			cout << f(m, k, reall) << " ";
			timer--;
			reall++;
			if (timer == 0) {
				reall = 1;
				cout << " | ";
				k++;
				timer = C[m][k];
			}
		}
		cout << endl;
	}
	cout << "test:" << f(4, 3, F(5, 3, 8)) << endl;;
	return 0;
}
		