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
	if (t > 10 || t < 1) {
		puts("Invalid Test");
		return 0;
	}
	while (t--) {
		string s;
		cin >> s;
		int upper = 0, lower = 0;
		bool alpha = 0;
		bool validSize = (1 <= s.size() && s.size() <= 100) ? 1 : 0; 
		for (char c : s) {
			if (isalpha(c)) alpha = 1;
			if (isupper(c)) upper++;
			else if (islower(c)) lower++;
		}
		if (!alpha || !validSize) puts("Invalid Input");
		else printf("%d\n", min(upper, lower));
	}
	return 0;
}
		