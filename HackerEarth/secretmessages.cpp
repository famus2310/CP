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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			int now = c;
			if (!isalpha(c) && !isdigit(c)) {
				cout << c;
				continue;
			}
			if (isdigit(c)) {
				int shifter = k % 10;
				now = c - '0';
				now = now + shifter;
				now = now % 10;
				now = now + '0';
			}
			else if (isupper(c)) {
				int shifter = k % 26;
				if (now + shifter > 'Z') now = now - 26;
				now += shifter;
			} else {
				int shifter = k % 26;
				// cout << (int)c;
				if (now + shifter > 'z') now = now - 26;
				now += shifter;
			}
			cout << (char)now;
		}
		puts("");
	}
	return 0;
}
		