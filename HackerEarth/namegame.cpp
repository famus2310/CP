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

bool isPrime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		for (char c : s) {
			int lo = c, hi = c;
			int ans;
			while (true) {
				if (isalpha(lo)) {
					if (isPrime(lo)) {
						ans = lo;
						break;
					} else lo--;
				} else lo--;
				if (isalpha(hi)) {
					if (isPrime(hi)) {
						ans = hi;
						break;
					} else hi++;
				} else hi++;
			}
			cout << (char)ans;
		}
		puts("");
	}
	return 0;
}
