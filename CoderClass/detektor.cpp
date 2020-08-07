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

string s;

bool isPal() {
	for (int i = 0; i < s.size() / 2; i++) if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		cin >> s;
		if (!isPal()) printf("bukan ");
		puts("palindrom");
	}
	return 0;
}
		