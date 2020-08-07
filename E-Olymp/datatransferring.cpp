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

char s[N], t[N];

int main() {
	scanf("%s", s);
	scanf("%s", t);
	int tr = 0;
	int ssz = sizeof(s);
	int tsz = sizeof(t);
	if (ssz != tsz) tr = 2;
	for (int i = 0; i < ssz - 1 && tr < 2; i++) {
		if (s[i] != t[i]) {
			if (s[i] == t[i + 1] && s[i + 1] == t[i]) {
				tr++;
				swap(s[i], s[i + 1]);
			}
			else 
				tr = 2;
		}
	}
	if (tr < 2) {
		puts("YES");
	} else 
		puts("NO");
	return 0;
}
		