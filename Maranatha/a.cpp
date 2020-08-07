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

string coded[256];
string inp;

int main() {	
	coded['a'] = "ei";
	coded['b'] = "bi";
	coded['c'] = "si";
	coded['d'] = "di";
	coded['e'] = "i";
	coded['f'] = "ef";
	coded['g'] = "dei";
	coded['h'] = "eitf";
	coded['i'] = "ai";
	coded['j'] = "djei";
	coded['k'] = "kei";
	coded['l'] = "el";
	coded['m'] = "em";
	coded['n'] = "en";
	coded['o'] = "ou";
	coded['p'] = "pi";
	coded['q'] = "kiu";
	coded['r'] = "ar";
	coded['s'] = "es";
	coded['t'] = "ti";
	coded['u'] = "ju";
	coded['v'] = "vi";
	coded['w'] = "dabelju";
	coded['x'] = "eks";
	coded['y'] = "wai";
	coded['z'] = "zi";
	getline(cin, inp);
	string ret;
	for (char c : inp) {
		if ('a' <= c && c <= 'z') cout << coded[c];
		else cout << c;
	} 
	puts("");
 	return 0;
}
		