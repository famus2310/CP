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

//C scale : C, F, G | A scale : A, D, E
string s;

int main() { 
	fastio;
	cin >> s; 
	int c = 0;
	int a = 0;
	char last;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || s[i - 1] == '|') {
			char x = s[i];
			c += (x == 'C' || x == 'F' || x == 'G');
			a += (x == 'A' || x == 'D' || x == 'E');
			// last = x;
		}	
	}
	last = s.back();
	if (a > c)
		puts("A-mol");
	else if (a < c)
		puts("C-dur");
	else if (last == 'A')
		puts("A-mol");
	else puts("C-dur");
	return 0;
}
		