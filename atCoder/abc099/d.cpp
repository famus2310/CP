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

LL n, c;
LL C[37][37];
LL grid[505][505];
LL diff[37][3];

int main() {
	memset(diff, 0, sizeof(diff));
	scanf("%lld %lld" ,&n, &c);
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			cin >> C[i][j];
			diff[C[i][j]][(i + j) % 3]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		LL mn = INF;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) continue;
				
			}
		}
	}
	return 0; 
}
		