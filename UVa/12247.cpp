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

int A[3], B[3];
int cnt[55];

int main() {
	int a, b, c, d, e;
	while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) == 5, (a || b || c || d || e)) {
		memset(cnt, 0, sizeof cnt);
		A[0] = a; A[1] = b; A[2] = c;
		B[0] = d; B[1] = e;
		cnt[a] = cnt[b] = cnt[c] = cnt[d] = cnt[e] = 1;
		sort(A, A + 3);
		sort(B, B + 2);
		if (B[0] > A[2]) {
			for (int i = 1; i <= 53; i++) {
				if (i == 52) {
					puts("-1");
					break;
				}
				if (cnt[i] == 0) {
					printf("%d\n", i);
					break;
				}
			}
		} else if (B[0] < A[1] && B[1] < A[2]) {
			puts("-1");
		} else {
			if (B[0] > A[1]) {
				for (int i = A[1]; i <= 53; i++) {
					if (i == 53) {
						puts("-1");
						break;
					}
					if (cnt[i] == 0) {
						printf("%d\n", i);
						break;
					}
				}
			}
			else if (B[0] > A[0]) {
				for (int i = A[2]; i <= 53; i++) {
					if (i == 53) {
						puts("-1");
						break;
					}
					if (cnt[i] == 0) {
						printf("%d\n", i);
						break;
					}
				}
			} else {
				for (int i = A[2]; i <= 53; i++) {
					if (i == 53) {
						puts("-1");
						break;
					}
					if (cnt[i] == 0) {
						printf("%d\n", i);
						break;
					}
				}
			}
		}
	}
	return 0;
}
		