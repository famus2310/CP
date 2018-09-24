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

const int NMAX = 1e5 + 5;

bool isUpper(string s) {
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') return true;
	}
	return false;
}

int main() {
	int p, t;
	scanf("%d %d", &p, &t);
	int cnt = 0;
	for (int i = 0; i < p; i++) {
		bool ans = 1;
		for (int j = 0; j < t; j++) {
			string s;
			cin >> s;
			s[0] = tolower(s[0]);
			if (isUpper(s)) ans = 0;
		}
		if (ans) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
		