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

int cntA[N], cntB[N];
set<int> A, B;

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) == 2, (a || b)) {
		memset(cntA, 0, sizeof cntA);
		memset(cntB, 0, sizeof cntB);
		A.clear(); B.clear();
		for (int i = 0; i < a; i++) {
			int x;
			scanf("%d", &x);
			A.insert(x);
			cntA[x]++;
		} 
		for (int i = 0; i < b; i++) {
			int x;
			scanf("%d", &x);
			B.insert(x);
			cntB[x]++;
		}
		int sumA = 0;
		int sumB = 0;
		for (int it : A) {
			if (cntB[it] == 0) sumA++;
		}
		for (int it : B) {
			if (cntA[it] == 0) sumB++;
		}
		// cout << sumA << " " << sumB << endl;
		printf("%d\n", min(sumB, sumA));
	}
	return 0;
}
		